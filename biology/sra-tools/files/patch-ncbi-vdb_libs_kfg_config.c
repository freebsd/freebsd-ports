--- ncbi-vdb/libs/kfg/config.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/kfg/config.c
@@ -2574,7 +2574,7 @@ bool load_from_std_location ( KConfig *self, const KDi
     const char * std_locs [] =
     {
 #if ! WINDOWS
-        "/etc/ncbi",
+        "/usr/local/etc/ncbi",
 #else
         "/c/ncbi",
 #endif
@@ -2588,7 +2588,7 @@ bool load_from_std_location ( KConfig *self, const KDi
         NCBI_VDB_NO_ETC_NCBI_KFG[0] != '\0')
     {
         DBGMSG(DBG_KFG, DBG_FLAG(DBG_KFG),
-            ("KFG: load from std. location /etc/ncbi is disabled. "
+            ("KFG: load from std. location /usr/local/etc/ncbi is disabled. "
                 "NCBI_VDB_NO_ETC_NCBI_KFG='%s'\n", NCBI_VDB_NO_ETC_NCBI_KFG));
         return loaded;
     }
@@ -2839,7 +2839,9 @@ void add_predefined_nodes ( KConfig * self, const char
     update_node ( self, "kfg/arch/bits", buf, true );
 
     /* *OS */
-#if LINUX
+#if BSD
+    #define OS "bsd"
+#elif LINUX
     #define OS "linux"
 #elif MAC
     #define OS "mac"
