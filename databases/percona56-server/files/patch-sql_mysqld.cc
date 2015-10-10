--- sql/mysqld.cc.orig	2015-07-25 17:06:21 UTC
+++ sql/mysqld.cc
@@ -2117,6 +2117,16 @@
 #ifndef EMBEDDED_LIBRARY

 /* Initialise proxy protocol. */
+
+/* At least OpenBSD and NexentaCore do not
+* define s6_addr32 for user land settings.
+*/
+#if !defined s6_addr32 && defined __sun__
+#       define s6_addr32 _S6_un._S6_u32
+#elif !defined s6_addr32 && ( defined __OpenBSD__ || defined __FreeBSD__ )
+#       define s6_addr32 __u6_addr.__u6_addr32
+#endif  /* !defined s6_addr32 */
+
 static void set_proxy()
 {
   const char *p;
