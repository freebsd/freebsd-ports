--- jsrc/jeload.c.orig	2019-03-10 11:13:19 UTC
+++ jsrc/jeload.c
@@ -330,6 +330,8 @@ int jefirst(int type,char* arg)
 	strcat(input,"[UNAME_z_=:'Win'");
 #elif defined(__MACH__)
 	strcat(input,"[UNAME_z_=:'Darwin'");
+#elif defined(__FreeBSD__)
+	strcat(input,"[UNAME_z_=:'FreeBSD'");
 #elif !defined(ANDROID)
 	strcat(input,"[UNAME_z_=:'Linux'");
 #endif
