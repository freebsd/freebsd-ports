--- libdrizzle-1.0/libdrizzle/handshake.c.orig	2026-11-06 18:08:06 UTC
+++ libdrizzle-1.0/libdrizzle/handshake.c
@@ -42,6 +42,15 @@
 #include "common.h"
 
 /*
+ * Private declarations
+ */
+
+/**
+ * Handle an auth switch request or auth more data packet.
+ */
+static drizzle_return_t _handshake_auth_read(drizzle_con_st *con);
+
+/*
  * Client Definitions
  */
 
@@ -189,9 +198,19 @@ drizzle_return_t drizzle_state_handshake_server_read(d
   con->buffer_ptr+= 1;
 
   con->status= drizzle_get_byte2(con->buffer_ptr);
-  /* Skip status and filler. */
-  con->buffer_ptr+= 15;
+  con->buffer_ptr+= 2;
 
+  /* The upper 16 bits of the capabilities, which the 2 byte field above
+     cannot carry. Needed to find out whether the server negotiates the
+     authentication plugin at all. */
+  con->server_capabilities= (uint32_t)con->capabilities |
+                            ((uint32_t)drizzle_get_byte2(con->buffer_ptr)
+                             << 16);
+
+  /* Skip the upper capabilities, the length of the auth plugin data and the
+     reserved bytes. */
+  con->buffer_ptr+= 13;
+
   memcpy(con->scramble + 8, con->buffer_ptr, 12);
   con->buffer_ptr+= 13;
 
@@ -203,6 +222,25 @@ drizzle_return_t drizzle_state_handshake_server_read(d
   memcpy(con->server_extra, (char *)con->buffer_ptr, extra_length);
   con->server_extra[extra_length]= 0;
 
+  /* Name of the plugin the server wants to start the authentication with. */
+  con->auth_plugin[0]= 0;
+  if (con->server_capabilities & DRIZZLE_CAPABILITIES_PLUGIN_AUTH)
+  {
+    size_t left= (size_t)(packet_end - con->buffer_ptr);
+
+    if (left > (DRIZZLE_MAX_AUTH_PLUGIN_SIZE - 1))
+      left= DRIZZLE_MAX_AUTH_PLUGIN_SIZE - 1;
+
+    memcpy(con->auth_plugin, con->buffer_ptr, left);
+    con->auth_plugin[left]= 0;
+  }
+
+  if (con->auth_plugin[0] == 0)
+  {
+    snprintf(con->auth_plugin, DRIZZLE_MAX_AUTH_PLUGIN_SIZE, "%s",
+             DRIZZLE_AUTH_PLUGIN_NATIVE);
+  }
+
   con->buffer_size-= con->packet_size;
   if (con->buffer_size != 0)
   {
@@ -472,34 +510,10 @@ drizzle_return_t drizzle_state_handshake_client_write(
   uint8_t *ptr;
   drizzle_capabilities_t capabilities;
   drizzle_return_t ret;
+  size_t plugin_size= 0;
 
   drizzle_log_debug(con->drizzle, "drizzle_state_handshake_client_write");
 
-  /* Calculate max packet size. */
-  con->packet_size= 4   /* Capabilities */
-                  + 4   /* Max packet size */
-                  + 1   /* Charset */
-                  + 23  /* Unused */
-                  + strlen(con->user) + 1
-                  + 1   /* Scramble size */
-                  + DRIZZLE_MAX_SCRAMBLE_SIZE
-                  + strlen(con->db) + 1;
-
-  /* Assume the entire handshake packet will fit in the buffer. */
-  if ((con->packet_size + 4) > DRIZZLE_MAX_BUFFER_SIZE)
-  {
-    drizzle_set_error(con->drizzle, "drizzle_state_handshake_client_write",
-                      "buffer too small:%zu", con->packet_size + 4);
-    return DRIZZLE_RETURN_INTERNAL_ERROR;
-  }
-
-  ptr= con->buffer_ptr;
-
-  /* Store packet size at the end since it may change. */
-  ptr[3]= con->packet_number;
-  con->packet_number++;
-  ptr+= 4;
-
   if (con->options & DRIZZLE_CON_MYSQL)
     con->capabilities|= DRIZZLE_CAPABILITIES_PROTOCOL_41;
 
@@ -517,15 +531,63 @@ drizzle_return_t drizzle_state_handshake_client_write(
     capabilities|= DRIZZLE_CAPABILITIES_MULTI_STATEMENTS;
   }
 
-  if (con->options & DRIZZLE_CON_AUTH_PLUGIN)
+  capabilities&= ~(DRIZZLE_CAPABILITIES_COMPRESS | DRIZZLE_CAPABILITIES_SSL);
+  if (con->db[0] == 0)
+    capabilities&= ~DRIZZLE_CAPABILITIES_CONNECT_WITH_DB;
+
+  /* Only negotiate the plugin if the server offered to. Against a server
+     that did not, the packet stays byte for byte the one we always sent. */
+  if ((con->options & DRIZZLE_CON_MYSQL) &&
+      ((con->server_capabilities & DRIZZLE_CAPABILITIES_PLUGIN_AUTH) ||
+       (con->options & DRIZZLE_CON_AUTH_PLUGIN)))
   {
     capabilities|= DRIZZLE_CAPABILITIES_PLUGIN_AUTH;
+    plugin_size= strlen(con->auth_plugin) + 1;
   }
+  else if (con->options & DRIZZLE_CON_MYSQL)
+  {
+    snprintf(con->auth_plugin, DRIZZLE_MAX_AUTH_PLUGIN_SIZE, "%s",
+             DRIZZLE_AUTH_PLUGIN_NATIVE);
+  }
 
-  capabilities&= ~(DRIZZLE_CAPABILITIES_COMPRESS | DRIZZLE_CAPABILITIES_SSL);
-  if (con->db[0] == 0)
-    capabilities&= ~DRIZZLE_CAPABILITIES_CONNECT_WITH_DB;
+  if (con->options & DRIZZLE_CON_RAW_SCRAMBLE && con->scramble != NULL)
+  {
+    memcpy(con->auth_response, con->scramble, DRIZZLE_MAX_SCRAMBLE_SIZE);
+    con->auth_response_size= DRIZZLE_MAX_SCRAMBLE_SIZE;
+  }
+  else
+  {
+    ret= drizzle_auth_build(con);
+    if (ret != DRIZZLE_RETURN_OK)
+      return ret;
+  }
 
+  /* Calculate max packet size. */
+  con->packet_size= 4   /* Capabilities */
+                  + 4   /* Max packet size */
+                  + 1   /* Charset */
+                  + 23  /* Unused */
+                  + strlen(con->user) + 1
+                  + 1   /* Auth response size */
+                  + con->auth_response_size
+                  + strlen(con->db) + 1
+                  + plugin_size;
+
+  /* Assume the entire handshake packet will fit in the buffer. */
+  if ((con->packet_size + 4) > DRIZZLE_MAX_BUFFER_SIZE)
+  {
+    drizzle_set_error(con->drizzle, "drizzle_state_handshake_client_write",
+                      "buffer too small:%zu", con->packet_size + 4);
+    return DRIZZLE_RETURN_INTERNAL_ERROR;
+  }
+
+  ptr= con->buffer_ptr;
+
+  /* Store packet size at the end since it may change. */
+  ptr[3]= con->packet_number;
+  con->packet_number++;
+  ptr+= 4;
+
   drizzle_set_byte4(ptr, capabilities);
   ptr+= 4;
 
@@ -542,6 +604,12 @@ drizzle_return_t drizzle_state_handshake_client_write(
   if (ret != DRIZZLE_RETURN_OK)
     return ret;
 
+  if (plugin_size > 0)
+  {
+    memcpy(ptr, con->auth_plugin, plugin_size);
+    ptr+= plugin_size;
+  }
+
   con->buffer_size+= (4 + con->packet_size);
 
   /* Make sure we packed it correctly. */
@@ -567,6 +635,23 @@ drizzle_return_t drizzle_state_handshake_result_read(d
 
   drizzle_log_debug(con->drizzle, "drizzle_state_handshake_result_read");
 
+  /* The auth packets below have to look at the packet before the result
+     parser gets to see it, so make sure it is complete. */
+  if (con->buffer_size < con->packet_size)
+  {
+    drizzle_state_push(con, drizzle_state_read);
+    return DRIZZLE_RETURN_OK;
+  }
+
+  if ((con->options & DRIZZLE_CON_MYSQL) &&
+      !(con->options & DRIZZLE_CON_RAW_PACKET) &&
+      ((con->buffer_ptr[0] == 0x01 && con->packet_size >= 2) ||
+       (con->buffer_ptr[0] == 0xfe && con->packet_size > 5 &&
+        (con->server_capabilities & DRIZZLE_CAPABILITIES_PLUGIN_AUTH))))
+  {
+    return _handshake_auth_read(con);
+  }
+
   if (drizzle_result_create(con, &result) == NULL)
     return DRIZZLE_RETURN_MEMORY;
 
@@ -594,4 +679,158 @@ drizzle_return_t drizzle_state_handshake_result_read(d
     return DRIZZLE_RETURN_HANDSHAKE_FAILED;
 
   return ret;
+}
+
+drizzle_return_t drizzle_state_auth_write(drizzle_con_st *con)
+{
+  uint8_t *ptr;
+
+  drizzle_log_debug(con->drizzle, "drizzle_state_auth_write");
+
+  con->packet_size= con->auth_response_size;
+
+  if ((con->packet_size + 4) > DRIZZLE_MAX_BUFFER_SIZE)
+  {
+    drizzle_set_error(con->drizzle, "drizzle_state_auth_write",
+                      "buffer too small:%zu", con->packet_size + 4);
+    return DRIZZLE_RETURN_INTERNAL_ERROR;
+  }
+
+  ptr= con->buffer_ptr;
+
+  drizzle_set_byte3(ptr, con->packet_size);
+  ptr[3]= con->packet_number;
+  con->packet_number++;
+  ptr+= 4;
+
+  if (con->packet_size > 0)
+    memcpy(ptr, con->auth_response, con->packet_size);
+
+  con->buffer_size+= (4 + con->packet_size);
+
+  drizzle_state_pop(con);
+  return DRIZZLE_RETURN_OK;
+}
+
+/*
+ * Private definitions
+ */
+
+static drizzle_return_t _handshake_auth_read(drizzle_con_st *con)
+{
+  drizzle_return_t ret;
+  uint8_t *ptr= con->buffer_ptr;
+  size_t size= con->packet_size;
+  uint8_t type= ptr[0];
+
+  /* Take the packet out of the buffer, the response is written over it. */
+  con->buffer_ptr+= size;
+  con->buffer_size-= size;
+  con->packet_size= 0;
+  if (con->buffer_size == 0)
+    con->buffer_ptr= con->buffer;
+
+  if (type == 0xfe)
+  {
+    /* Auth switch request: the plugin to use, then a fresh scramble. */
+    uint8_t *end= memchr(ptr + 1, 0, size - 1);
+    size_t name_size;
+
+    if (end == NULL)
+    {
+      drizzle_set_error(con->drizzle, "_handshake_auth_read",
+                        "no plugin name in the auth switch packet");
+      return DRIZZLE_RETURN_BAD_PACKET;
+    }
+
+    name_size= (size_t)(end - (ptr + 1));
+    if (name_size == 0 || name_size >= DRIZZLE_MAX_AUTH_PLUGIN_SIZE)
+    {
+      drizzle_set_error(con->drizzle, "_handshake_auth_read",
+                        "bad plugin name size:%zu", name_size);
+      return DRIZZLE_RETURN_BAD_PACKET;
+    }
+
+    if (((size_t)(end + 1 - ptr) + DRIZZLE_MAX_SCRAMBLE_SIZE) > size)
+    {
+      drizzle_set_error(con->drizzle, "_handshake_auth_read",
+                        "no scramble in the auth switch packet");
+      return DRIZZLE_RETURN_BAD_PACKET;
+    }
+
+    memcpy(con->auth_plugin, ptr + 1, name_size);
+    con->auth_plugin[name_size]= 0;
+
+    con->scramble= con->scramble_buffer;
+    memcpy(con->scramble, end + 1, DRIZZLE_MAX_SCRAMBLE_SIZE);
+
+    drizzle_log_debug(con->drizzle, "auth switch to %s", con->auth_plugin);
+
+    ret= drizzle_auth_build(con);
+    if (ret != DRIZZLE_RETURN_OK)
+      return ret;
+  }
+  else if (ptr[1] == 0x03)
+  {
+    /* caching_sha2_password: the server had the hash cached, the result
+       packet follows. */
+    drizzle_log_debug(con->drizzle, "fast authentication succeeded");
+
+    drizzle_state_pop(con);
+    drizzle_state_push(con, drizzle_state_handshake_result_read);
+    drizzle_state_push(con, drizzle_state_packet_read);
+    return DRIZZLE_RETURN_OK;
+  }
+  else if (ptr[1] == 0x04)
+  {
+    /* caching_sha2_password: the hash was not cached. Over a unix socket the
+       password may go in the clear, over tcp it has to be encrypted with the
+       public key of the server. */
+    if (con->socket_type == DRIZZLE_CON_SOCKET_UDS)
+    {
+      size_t pw_size= strlen(con->password) + 1;
+
+      if (pw_size > DRIZZLE_MAX_AUTH_RESPONSE_SIZE)
+      {
+        drizzle_set_error(con->drizzle, "_handshake_auth_read",
+                          "password too long:%zu", pw_size);
+        return DRIZZLE_RETURN_INTERNAL_ERROR;
+      }
+
+      memcpy(con->auth_response, con->password, pw_size);
+      con->auth_response_size= pw_size;
+    }
+    else if (con->options & DRIZZLE_CON_AUTH_NO_RSA)
+    {
+      drizzle_set_error(con->drizzle, "_handshake_auth_read",
+                        "%s needs the server public key", con->auth_plugin);
+      return DRIZZLE_RETURN_AUTH_FAILED;
+    }
+    else
+    {
+      con->auth_response[0]= 0x02;
+      con->auth_response_size= 1;
+    }
+  }
+  else if (ptr[1] == '-')
+  {
+    /* The server sent its public key in PEM form. */
+    ret= drizzle_auth_build_rsa(con, (char *)(ptr + 1), size - 1);
+    if (ret != DRIZZLE_RETURN_OK)
+      return ret;
+  }
+  else
+  {
+    drizzle_set_error(con->drizzle, "_handshake_auth_read",
+                      "unsupported authentication data:%u", ptr[1]);
+    return DRIZZLE_RETURN_AUTH_FAILED;
+  }
+
+  drizzle_state_pop(con);
+  drizzle_state_push(con, drizzle_state_handshake_result_read);
+  drizzle_state_push(con, drizzle_state_packet_read);
+  drizzle_state_push(con, drizzle_state_write);
+  drizzle_state_push(con, drizzle_state_auth_write);
+
+  return DRIZZLE_RETURN_OK;
 }
