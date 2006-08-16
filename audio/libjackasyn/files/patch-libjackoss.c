--- libjackoss.c	Mon Mar  6 08:17:57 2006
+++ libjackoss.c	Tue Aug 15 17:36:31 2006
@@ -32,7 +32,9 @@
 #define REAL_LIBC ((void *) -1L)
 #endif
 
-
+#if defined (__FreeBSD__)
+#define O_LARGEFILE 0
+#endif
 
 #if 1
 int (*_select)(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
@@ -119,7 +121,7 @@
   }
 
   va_start (args, flags);
-  mode = va_arg (args, mode_t);
+  mode = va_arg (args, int);
   va_end (args);
 
   if ((strncmp(name,"/dev/dsp",8) && strncmp(name,"/dev/audio",8))
@@ -198,7 +200,7 @@
         DEBUG(fprintf(stderr,"%s\n",__FUNCTION__));
         if (oflag & O_CREAT) {
                 va_start(args, oflag);
-                mode = va_arg(args, mode_t);
+                mode = va_arg(args, int);
                 va_end(args);
         }
         return jackoss_open(file, oflag | O_LARGEFILE, mode);
@@ -386,10 +388,10 @@
     UNIMPLEMENTED( SNDCTL_DSP_MAPOUTBUF);
     UNIMPLEMENTED( SNDCTL_DSP_SETSYNCRO);
     UNIMPLEMENTED( SNDCTL_DSP_SETDUPLEX);
-    UNIMPLEMENTED( SNDCTL_DSP_GETCHANNELMASK);
-    UNIMPLEMENTED( SNDCTL_DSP_BIND_CHANNEL);
-    UNIMPLEMENTED( SNDCTL_DSP_SETSPDIF);
-    UNIMPLEMENTED( SNDCTL_DSP_GETSPDIF);
+//    UNIMPLEMENTED( SNDCTL_DSP_GETCHANNELMASK);
+//    UNIMPLEMENTED( SNDCTL_DSP_BIND_CHANNEL);
+//    UNIMPLEMENTED( SNDCTL_DSP_SETSPDIF);
+//    UNIMPLEMENTED( SNDCTL_DSP_GETSPDIF);
 
   default:
     fprintf(stderr,"unknown ioctl\n");
