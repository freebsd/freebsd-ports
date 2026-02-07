--- extio.c.orig	2014-11-04 10:25:00 UTC
+++ extio.c
@@ -335,7 +335,7 @@ if(cnt >= 0 && thread_status_flag[THREAD_EXTIO_INPUT] 
     for(i=0; i<j; i++)
       {
       iz=(int*)&timf1_char[timf1p_sdr];
-      iz[0]=(int)(0x7fffffff*z[i]);
+      iz[0]=(int)((float)0x7fffffff*z[i]);
       timf1p_sdr=(timf1p_sdr+4)&timf1_bytemask;
       }
     break;
@@ -369,7 +369,7 @@ char *dirs[]={"./",
               "/usr/lib",
               "/usr/lib32",
               "/usr/lib32/lib",
-              "/usr/local/lib",
+              "%%LOCALBASE%%/lib",
               "/usr/local32/lib",
               "/emul/ia32-linux/lib",
               "/emul/ia32-linux/usr/lib",              
@@ -381,7 +381,7 @@ char *dirs[]={"./",
               "/lib64",
               "/usr/lib",
               "/usr/lib64",
-              "/usr/local/lib",
+              "%%LOCALBASE%%/lib",
               "/usr/lib/x86_64-linux-gnu",
               "X"};
 #endif
