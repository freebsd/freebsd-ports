--- funkgold_misc.c.orig	Thu Apr 14 17:48:48 2005
+++ funkgold_misc.c	Thu Apr 14 17:49:42 2005
@@ -30,22 +30,7 @@
 
 void get_environment(void)
 {
-  char *os_type = getenv("OSTYPE");
-  register int x;
-  char *os_tt[] = {
-    "Linux",
-    "FreeBSD"
-  };
-
-  for(x = 0;x < SO_TT_SIZE;x++)
-    if(strcmp(os_tt[x],os_type) == 0)
-      break;
-  switch(x)
-  {
-    case 0:  funk_info.funk_cpu_type = FKCPU_LINUX; break;
-    case 1:  funk_info.funk_cpu_type = FKCPU_FREEBSD; break;
-    default: funk_info.funk_cpu_type = FKCPU_UNKNOWN; break;
-  }
+  funk_info.funk_cpu_type = FKCPU_FREEBSD;
 }
 
 /***************************************************************************
