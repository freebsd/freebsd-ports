--- glib/glib-unix.c.orig	2021-09-17 10:17:56 UTC
+++ glib/glib-unix.c
@@ -463,7 +463,6 @@ g_unix_get_passwd_entry (const gchar  *user_name,
     } *buffer = NULL;
   gsize string_buffer_size = 0;
   GError *local_error = NULL;
-  int errsv = 0;
 
   g_return_val_if_fail (user_name != NULL, NULL);
   g_return_val_if_fail (error == NULL || *error == NULL, NULL);
@@ -493,10 +492,8 @@ g_unix_get_passwd_entry (const gchar  *user_name,
        */
       buffer = g_malloc0 (sizeof (*buffer) + string_buffer_size + 6);
 
-      errno = 0;
       retval = getpwnam_r (user_name, &buffer->pwd, buffer->string_buffer,
                            string_buffer_size, &passwd_file_entry);
-      errsv = errno;
 
       /* Bail out if: the lookup was successful, or if the user id can't be
        * found (should be pretty rare case actually), or if the buffer should be
@@ -508,19 +505,19 @@ g_unix_get_passwd_entry (const gchar  *user_name,
           break;
         }
       else if (retval == 0 ||
-          errsv == ENOENT || errsv == ESRCH ||
-          errsv == EBADF || errsv == EPERM)
+          retval == ENOENT || retval == ESRCH ||
+          retval == EBADF || retval == EPERM)
         {
           /* Username not found. */
-          g_unix_set_error_from_errno (&local_error, errsv);
+          g_unix_set_error_from_errno (&local_error, retval);
           break;
         }
-      else if (errsv == ERANGE)
+      else if (retval == ERANGE)
         {
           /* Can’t allocate enough string buffer space. */
           if (string_buffer_size > 32 * 1024)
             {
-              g_unix_set_error_from_errno (&local_error, errsv);
+              g_unix_set_error_from_errno (&local_error, retval);
               break;
             }
 
@@ -529,7 +526,7 @@ g_unix_get_passwd_entry (const gchar  *user_name,
         }
       else
         {
-          g_unix_set_error_from_errno (&local_error, errsv);
+          g_unix_set_error_from_errno (&local_error, retval);
           break;
         }
     }
@@ -543,7 +540,6 @@ g_unix_get_passwd_entry (const gchar  *user_name,
     {
       g_clear_pointer (&buffer, g_free);
       g_propagate_error (error, g_steal_pointer (&local_error));
-      errno = errsv;
     }
 
   return (struct passwd *) g_steal_pointer (&buffer);
