--- m3-libs/m3core/src/unix/Common/Unetdb.c.orig	2010-04-04 11:59:31.000000000 +0000
+++ m3-libs/m3core/src/unix/Common/Unetdb.c
@@ -35,23 +35,31 @@ struct _m3_hostent_t
 static m3_hostent_t* native_to_m3(const hostent_t* native, m3_hostent_t* m3)
 {
     if (native == NULL)
+    {
         return NULL;
-    m3->name = native->h_name;
-    m3->aliases = native->h_aliases;
-    m3->addrtype = native->h_addrtype;
-    m3->length = native->h_length;
-    m3->addr_list = native->h_addr_list;
+    }
+    else
+    {
+        m3->name = native->h_name;
+        m3->aliases = native->h_aliases;
+        m3->addrtype = native->h_addrtype;
+        m3->length = native->h_length;
+        m3->addr_list = native->h_addr_list;
+    }
+    Scheduler__EnableSwitching();
     return m3;
 }
 
 m3_hostent_t* Unetdb__gethostbyname(const char* name, m3_hostent_t* m3)
 {
+    Scheduler__DisableSwitching();
     return native_to_m3(gethostbyname(name), m3);
 }
 
 m3_hostent_t*
 Unetdb__gethostbyaddr(const char* addr, int len, int type, m3_hostent_t* m3)
 {
+    Scheduler__DisableSwitching();
     return native_to_m3(gethostbyaddr(addr, len, type), m3);
 }
 
