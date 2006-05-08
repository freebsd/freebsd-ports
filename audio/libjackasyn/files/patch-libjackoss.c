--- libjackoss.c	Mon Mar  6 07:19:23 2006
+++ libjackoss.c	Mon Mar  6 12:25:46 2006
@@ -117,7 +117,7 @@
   }
 
   va_start (args, flags);
-  mode = va_arg (args, mode_t);
+  mode = va_arg (args, int);
   va_end (args);
 
   if ((strncmp(name,"/dev/dsp",8) && strncmp(name,"/dev/audio",8))
@@ -367,10 +367,10 @@
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
