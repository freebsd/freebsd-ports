--- obuffer.cc.orig	Mon Jun 27 21:14:03 1994
+++ obuffer.cc	Thu Nov 21 16:45:14 2002
@@ -47,7 +47,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#include <iostream.h>
+#include <iostream>
 #include "obuffer.h"
 #include "header.h"
 #ifdef ULAW
@@ -65,14 +65,14 @@
 #ifdef DEBUG
   if (!number_of_channels || number_of_channels > MAXCHANNELS)
   {
-    cerr << "FileObuffer: number of channels has to be in [1, " <<  MAXCHANNELS << "] !\n";
+    std::cerr << "FileObuffer: number of channels has to be in [1, " <<  MAXCHANNELS << "] !\n";
     exit (1);
   }
 #endif
 
 #ifdef ULAW
   if (number_of_channels > 1)
-    cerr << "Are you sure you need stereo u-law output?\n";
+    std::cerr << "Are you sure you need stereo u-law output?\n";
 #endif
   channels = number_of_channels;
   for (int i = 0; i < number_of_channels; ++i)
@@ -85,12 +85,12 @@
 #ifdef DEBUG
   if (channel >= channels)
   {
-    cerr << "illegal channelnumber in FileObuffer::append()!\n";
+    std::cerr << "illegal channelnumber in FileObuffer::append()!\n";
     exit (1);
   }
   if (bufferp[channel] - buffer >= OBUFFERSIZE)
   {
-    cerr << "FileObuffer: buffer overflow!\n";
+    std::cerr << "FileObuffer: buffer overflow!\n";
     exit (1);
   }
 #endif
@@ -143,7 +143,7 @@
 #ifdef DEBUG
   if (!number_of_channels || number_of_channels > MAXCHANNELS)
   {
-    cerr << "IndigoObuffer: number of channels has to be in [1, " <<  MAXCHANNELS << "] !\n";
+    std::cerr << "IndigoObuffer: number of channels has to be in [1, " <<  MAXCHANNELS << "] !\n";
     exit (1);
   }
 #endif
@@ -155,7 +155,7 @@
   ALconfig config;
   if (!(config = ALnewconfig ()))
   {
-    cerr << "ALnewconfig failed!\n";
+    std::cerr << "ALnewconfig failed!\n";
     exit (1);
   }
   ALsetwidth (config, AL_SAMPLE_16);
@@ -165,7 +165,7 @@
     ALsetchannels (config, AL_STEREO);
   if (!(port = ALopenport ("MPEG audio player", "w", config)))
   {
-    cerr << "can't allocate an audio port!\n";
+    std::cerr << "can't allocate an audio port!\n";
     exit (1);
   }
 
@@ -190,12 +190,12 @@
 #ifdef DEBUG
   if (channel >= channels)
   {
-    cerr << "illegal channelnumber in IndigoObuffer::append()!\n";
+    std::cerr << "illegal channelnumber in IndigoObuffer::append()!\n";
     exit (1);
   }
   if (bufferp[channel] - buffer >= OBUFFERSIZE)
   {
-    cerr << "IndigoObuffer: buffer overflow!\n";
+    std::cerr << "IndigoObuffer: buffer overflow!\n";
     exit (1);
   }
 #endif
@@ -217,17 +217,17 @@
 int SparcObuffer::audio_fd = -1;
 
 #ifdef ULAW
-SparcObuffer::SparcObuffer (Header *header, bool use_speaker, bool use_headphone, bool use_line_out)
+SparcObuffer::SparcObuffer (Header *header, boolean use_speaker, boolean use_headphone, boolean use_line_out)
 #else
 SparcObuffer::SparcObuffer (uint32 number_of_channels, Header *header,
-			    bool use_speaker, bool use_headphone, bool use_line_out)
+			    boolean use_speaker, boolean use_headphone, boolean use_line_out)
 #endif
 {
 #ifndef ULAW
 #ifdef DEBUG
   if (!number_of_channels || number_of_channels > MAXCHANNELS)
   {
-    cerr << "SparcObuffer: 0 < number of channels < " << MAXCHANNELS << "!\n";
+    std::cerr << "SparcObuffer: 0 < number of channels < " << MAXCHANNELS << "!\n";
     exit (1);
   }
 #endif
@@ -235,7 +235,7 @@
 
   if (audio_fd < 0)
   {
-    cerr << "Internal error: SparcObuffer::audio_fd has to be initialized\n"
+    std::cerr << "Internal error: SparcObuffer::audio_fd has to be initialized\n"
 	    "by SparcObuffer::class_suitable()!\n";
     exit (1);
   }
@@ -296,7 +296,7 @@
 #ifdef DEBUG
   if (bufferp - buffer >= OBUFFERSIZE >> 1)
   {
-    cerr << "SparcObuffer: buffer overflow!\n";
+    std::cerr << "SparcObuffer: buffer overflow!\n";
     exit (1);
   }
 #endif
@@ -307,12 +307,12 @@
 #ifdef DEBUG
   if (channel >= channels)
   {
-    cerr << "illegal channelnumber in SparcObuffer::append()!\n";
+    std::cerr << "illegal channelnumber in SparcObuffer::append()!\n";
     exit (1);
   }
   if (bufferp[channel] - buffer >= OBUFFERSIZE)
   {
-    cerr << "SparcObuffer: buffer overflow!\n";
+    std::cerr << "SparcObuffer: buffer overflow!\n";
     exit (1);
   }
 #endif
@@ -351,7 +351,7 @@
   if ((fd = open ("/dev/audio", O_WRONLY | O_NDELAY, 0)) < 0)
     if (errno == EBUSY)
     {
-      cerr << "Sorry, the audio device is busy!\n";
+      std::cerr << "Sorry, the audio device is busy!\n";
       exit (1);
     }
     else
@@ -398,7 +398,7 @@
   }
   return devtype;
 #else
-  cerr << "SparcObuffer::get_device_type(): AUDIO_GETDEV ioctl not available!\n";
+  std::cerr << "SparcObuffer::get_device_type(): AUDIO_GETDEV ioctl not available!\n";
   return -1;
 #endif
 }
@@ -406,15 +406,15 @@
 
 
 #ifdef ULAW
-bool SparcObuffer::class_suitable (uint32 number_of_channels, bool force_amd)
+boolean SparcObuffer::class_suitable (uint32 number_of_channels, boolean force_amd)
 #else
-bool SparcObuffer::class_suitable (void)
+boolean SparcObuffer::class_suitable (void)
 #endif
 {
 #ifdef ULAW
   if (number_of_channels > 1)
   {
-    cerr << "Your audio hardware cannot handle more than one audio channel.\n"
+    std::cerr << "Your audio hardware cannot handle more than one audio channel.\n"
 	    "Please use the option -l or -r for stereo streams.\n";
     return False;
   }
@@ -436,7 +436,7 @@
       return True;
     else if (!strcmp (devtype.name, "SUNW,dbri"))
     {
-      cerr << "Your machine can produce CD-quality audio output,\n"
+      std::cerr << "Your machine can produce CD-quality audio output,\n"
 	      "but this binary was compiled for 8 kHz u-law ouput. (telephone quality)\n"
 	      "Please recompile it without the ULAW define in COMPILERFLAGS.\n"
 	      "(or use the -amd option to use this binary with low-quality output)\n";
@@ -448,7 +448,7 @@
       return True;
     else if (!strcmp (devtype.name, "SUNW,am79c30"))
     {
-      cerr << "Your machine can produce 8 kHz u-law audio output only,\n"
+      std::cerr << "Your machine can produce 8 kHz u-law audio output only,\n"
 	      "but this binary was compiled for CD-quality output.\n"
 	      "Please recompile it with ULAW defined in COMPILERFLAGS\n"
 	      "or use it in stdout mode as an decoder only.\n";
@@ -464,7 +464,7 @@
 #   ifdef ULAW
       return True;
 #   else
-      cerr << "Your machine can produce 8 kHz u-law audio output only,\n"
+      std::cerr << "Your machine can produce 8 kHz u-law audio output only,\n"
 	      "but this binary was compiled for CD-quality output.\n"
 	      "Please recompile it with ULAW defined in COMPILERFLAGS\n"
 	      "or use it in stdout mode as an decoder only.\n";
@@ -479,7 +479,7 @@
 	return True;
       else if (device_type == AUDIO_DEV_SPEAKERBOX)
       {
-	cerr << "Your machine can produce CD-quality audio output,\n"
+	std::cerr << "Your machine can produce CD-quality audio output,\n"
 		"but this binary was compiled for 8 kHz u-law ouput. (telephone quality)\n"
 		"Please recompile it without the ULAW define in COMPILERFLAGS.\n"
 		"(or use the -amd option to use this binary with low-quality output)\n";
@@ -491,7 +491,7 @@
 	return True;
       else if (device_type == AUDIO_DEV_AMD)
       {
-	cerr << "Your machine can produce 8 kHz u-law audio output only,\n"
+	std::cerr << "Your machine can produce 8 kHz u-law audio output only,\n"
 		"but this binary was compiled for CD-quality output.\n"
 		"Please recompile it with ULAW defined in COMPILERFLAGS\n"
 		"or use it in stdout mode as an decoder only.\n";
@@ -504,7 +504,7 @@
 
 #ifndef SunOS4_1_1
   close (audio_fd);
-  cerr << "Sorry, I don't recognize your audio device.\n"
+  std::cerr << "Sorry, I don't recognize your audio device.\n"
 # ifdef ULAW
 	  "Please try the -amd option or use the stdout mode.\n";
 # else
@@ -527,7 +527,7 @@
   if ((fd = open ("/dev/dsp", O_WRONLY | O_NDELAY, 0)) < 0)
     if (errno == EBUSY)
     {
-      cerr << "Sorry, the audio device is busy!\n";
+      std::cerr << "Sorry, the audio device is busy!\n";
       exit (1);
     }
     else
@@ -537,6 +537,7 @@
     }
 
   // turn NDELAY mode off:
+#ifndef __FreeBSD__	/* Our /dev/audio doesn't like non-blocking I/O */
   int flags;
   if ((flags = fcntl (fd, F_GETFL, 0)) < 0)
   {
@@ -549,6 +550,7 @@
     perror ("fcntl F_SETFL on /dev/audio failed");
     exit (1);
   }
+#endif
   return fd;
 }
 
@@ -558,7 +560,7 @@
 #ifdef DEBUG
   if (!number_of_channels || number_of_channels > MAXCHANNELS)
   {
-    cerr << "LinuxObuffer: 0 < number of channels < " << MAXCHANNELS << "!\n";
+    std::cerr << "LinuxObuffer: 0 < number of channels < " << MAXCHANNELS << "!\n";
     exit (1);
   }
 #endif
@@ -568,7 +570,7 @@
 
   if (audio_fd < 0)
   {
-    cerr << "Internal error, LinuxObuffer::audio_fd has to be initialized\n"
+    std::cerr << "Internal error, LinuxObuffer::audio_fd has to be initialized\n"
 	    "by LinuxObuffer::class_suitable()!\n";
     exit (1);
   }
@@ -602,12 +604,12 @@
 #ifdef DEBUG
   if (channel >= channels)
   {
-    cerr << "illegal channelnumber in LinuxObuffer::append()!\n";
+    std::cerr << "illegal channelnumber in LinuxObuffer::append()!\n";
     exit (1);
   }
   if (bufferp[channel] - buffer >= OBUFFERSIZE)
   {
-    cerr << "buffer overflow!\n";
+    std::cerr << "buffer overflow!\n";
     exit (1);
   }
 #endif
@@ -629,7 +631,7 @@
 }
 
 
-bool LinuxObuffer::class_suitable (uint32 number_of_channels)
+boolean LinuxObuffer::class_suitable (uint32 number_of_channels)
 {
   // open the dsp audio device:
   audio_fd = open_audio_device ();
