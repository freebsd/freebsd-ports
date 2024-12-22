--- src/rfc3315.c.orig	2024-12-20 21:57:21 UTC
+++ src/rfc3315.c
@@ -39,8 +39,8 @@ static void log6_quiet(struct state *state, char *type
 static void log6_opts(int nest, unsigned int xid, void *start_opts, void *end_opts);
 static void log6_packet(struct state *state, char *type, struct in6_addr *addr, char *string);
 static void log6_quiet(struct state *state, char *type, struct in6_addr *addr, char *string);
-static void *opt6_find (void *opts, void *end, unsigned int search, unsigned int minsize);
-static void *opt6_next(void *opts, void *end);
+static void *opt6_find (uint8_t *opts, uint8_t *end, unsigned int search, unsigned int minsize);
+static void *opt6_next(uint8_t *opts, uint8_t *end);
 static unsigned int opt6_uint(unsigned char *opt, int offset, int size);
 static void get_context_tag(struct state *state, struct dhcp_context *context);
 static int check_ia(struct state *state, void *opt, void **endp, void **ia_option);
@@ -61,11 +61,11 @@ static void calculate_times(struct dhcp_context *conte
 
 #define opt6_len(opt) ((int)(opt6_uint(opt, -2, 2)))
 #define opt6_type(opt) (opt6_uint(opt, -4, 2))
-#define opt6_ptr(opt, i) ((void *)&(((unsigned char *)(opt))[4+(i)]))
+#define opt6_ptr(opt, i) ((void *)&(((uint8_t *)(opt))[4+(i)]))
 
-#define opt6_user_vendor_ptr(opt, i) ((void *)&(((unsigned char *)(opt))[2+(i)]))
+#define opt6_user_vendor_ptr(opt, i) ((void *)&(((uint8_t *)(opt))[2+(i)]))
 #define opt6_user_vendor_len(opt) ((int)(opt6_uint(opt, -4, 2)))
-#define opt6_user_vendor_next(opt, end) (opt6_next(((void *) opt) - 2, end))
+#define opt6_user_vendor_next(opt, end) (opt6_next(((uint8_t *) opt) - 2, end))
  
 
 unsigned short dhcp6_reply(struct dhcp_context *context, int interface, char *iface_name,
@@ -107,11 +107,11 @@ static int dhcp6_maybe_relay(struct state *state, unsi
 static int dhcp6_maybe_relay(struct state *state, unsigned char *inbuff, size_t sz, 
 			     struct in6_addr *client_addr, int is_unicast, time_t now)
 {
-  void *end = inbuff + sz;
-  void *opts = inbuff + 34;
+  uint8_t *end = inbuff + sz;
+  uint8_t *opts = inbuff + 34;
   int msg_type = *inbuff;
   unsigned char *outmsgtypep;
-  void *opt;
+  uint8_t *opt;
   struct dhcp_vendor *vendor;
 
   /* if not an encapsulated relayed message, just do the stuff */
@@ -232,7 +232,7 @@ static int dhcp6_maybe_relay(struct state *state, unsi
   
   for (opt = opts; opt; opt = opt6_next(opt, end))
     {
-      if (opt6_ptr(opt, 0) + opt6_len(opt) > end) 
+      if ((uint8_t *)opt6_ptr(opt, 0) + opt6_len(opt) > end)
         return 0;
      
       /* Don't copy MAC address into reply. */
@@ -1307,7 +1307,7 @@ static int dhcp6_no_relay(struct state *state, int msg
      reallocated. */
   ((unsigned char *)(daemon->outpacket.iov_base))[start_msg] = outmsgtype;
 
-  log6_opts(0, state->xid, daemon->outpacket.iov_base + start_opts, daemon->outpacket.iov_base + save_counter(-1));
+  log6_opts(0, state->xid, (uint8_t *)daemon->outpacket.iov_base + start_opts, (uint8_t *)daemon->outpacket.iov_base + save_counter(-1));
   
   return 1;
 
@@ -2093,7 +2093,7 @@ static void log6_packet(struct state *state, char *typ
 	      string ? string : "");
 }
 
-static void *opt6_find (void *opts, void *end, unsigned int search, unsigned int minsize)
+static void *opt6_find (uint8_t *opts, uint8_t *end, unsigned int search, unsigned int minsize)
 {
   u16 opt, opt_len;
   void *start;
@@ -2120,7 +2120,7 @@ static void *opt6_find (void *opts, void *end, unsigne
     }
 }
 
-static void *opt6_next(void *opts, void *end)
+static void *opt6_next(uint8_t *opts, uint8_t *end)
 {
   u16 opt_len;
   
