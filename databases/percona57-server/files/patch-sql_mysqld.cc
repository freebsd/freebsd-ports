--- sql/mysqld.cc.orig	2016-11-27 19:44:54 UTC
+++ sql/mysqld.cc
@@ -1480,6 +1480,16 @@ static void clean_up_mutexes()
 ****************************************************************************/
 
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
