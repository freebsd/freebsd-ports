--- ref_gl/r_main.c.orig	2026-08-27 21:47:04 UTC
+++ ref_gl/r_main.c
@@ -1671,7 +1671,11 @@ int R_Init( void *hinstance, void *hWnd )
 		int		cores;
 		size_t	szrslt;
 		int     irslt;
+#if defined(__FreeBSD__)
+	fp = popen("/sbin/sysctl -n hw.ncpu","r");
+#else
         fp = popen("/bin/cat /proc/cpuinfo | grep -c '^processor'","r");
+#endif
         if ( fp == NULL )
         	goto cpuinfo_error;
         szrslt = fread(res, 1, sizeof(res)-1, fp);
@@ -1680,7 +1684,11 @@ int R_Init( void *hinstance, void *hWnd )
         if ( !szrslt )
         	goto cpuinfo_error;
 		cores = atoi( &res[0] );
+#if defined(__FreeBSD__)
+		fp = popen("/sbin/sysctl -n dev.cpu.0.freq_levels | cut -d / -f1","r");
+#else
 		fp = popen("/bin/cat /proc/cpuinfo | grep '^cpu MHz'","r");
+#endif
 		if ( fp == NULL )
 			goto cpuinfo_error;
         szrslt = fread(res, 1, sizeof(res)-1, fp);  // about 20 bytes/cpu
@@ -1688,14 +1696,18 @@ int R_Init( void *hinstance, void *hWnd )
 		pclose(fp);
 		if ( !szrslt )
 			goto cpuinfo_error;
+#if defined(__FreeBSD__)
+		irslt = sscanf( res, "%lf", &CPUTotalSpeed );
+#else
 		irslt = sscanf( res, "cpu MHz : %lf", &CPUTotalSpeed );
+#endif
 		if ( !irslt )
 			goto cpuinfo_error;
 		Com_Printf("...CPU: %4.2f Cores: %d\n", CPUTotalSpeed, cores);
-	    CPUTotalSpeed *= cores;
+
 	    goto cpuinfo_exit;
 cpuinfo_error:
-		Com_Printf("...Reading /proc/cpuinfo failed.\n");
+		Com_Printf("...Reading cpu info failed.\n");
 cpuinfo_exit:
 #endif
 
