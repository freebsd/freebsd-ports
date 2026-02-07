--- linux_a.c.orig	1996-05-20 13:09:46 UTC
+++ linux_a.c
@@ -71,12 +71,15 @@ PlayMode dpm = {
    then 8-bit unsigned if it fails. If you have a sound device that
    can't handle either, let me know. */
 
+/* Flag for Luigi Rizzo new sound driver (as opposed to VoxWare) */
+static int luigi_driver = 0;
+
 static int open_output(void)
 {
   int fd, tmp, i, warnings=0;
   
   /* Open the audio device */
-  fd=open(dpm.name, O_RDWR | O_NDELAY);
+  fd=open(dpm.name, O_RDWR);
   if (fd<0)
     {
       ctl->cmsg(CMSG_ERROR, VERB_NORMAL, "%s: %s",
@@ -84,6 +87,23 @@ static int open_output(void)
       return -1;
     }
 
+  /* Figure out if we're running with the Luigi driver or
+     the original VoxWare driver, with code based on dburr/luigi
+     in ports/5607.  It'd be great if we could do this before
+     opening the audio device, but oh well... */
+#if defined(AIOGFMT)	/* only defined in Luigi driver */
+  {
+    snd_chan_param s;
+    int i;
+    i = ioctl(fd, AIOGFMT, &s);
+    if (i != -1)
+      luigi_driver = 1;
+  }
+#endif
+
+  ctl->cmsg(CMSG_INFO, VERB_VERBOSE, "Using %s sound driver",
+	    luigi_driver ? "luigi" : "VoxWare");
+
   /* They can't mean these */
   dpm.encoding &= ~(PE_ULAW|PE_BYTESWAP);
 
@@ -92,6 +112,29 @@ static int open_output(void)
      the other one. */
 
   i=tmp=(dpm.encoding & PE_16BIT) ? 16 : 8;
+  if (luigi_driver)
+    {
+      if (dpm.encoding & PE_16BIT) {
+	int fmt = AFMT_S16_LE ;
+
+	if (ioctl(fd, SNDCTL_DSP_SETFMT, &fmt) < 0 || fmt != AFMT_S16_LE) {
+	    fmt = AFMT_U8 ;
+	    if (ioctl(fd, SNDCTL_DSP_SETFMT, &fmt) < 0 || fmt != AFMT_U8) {
+		ctl->cmsg(CMSG_ERROR, VERB_NORMAL,
+		      "%s doesn't support 16- or 8-bit sample width",
+		      dpm.name);
+		close(fd);
+		return -1;
+	    }
+	    ctl->cmsg(CMSG_WARNING, VERB_VERBOSE,
+		  "Sample width adjusted to %d bits", tmp);
+	    dpm.encoding ^= PE_16BIT;
+	    warnings = 1;
+	}
+      }
+    }
+  else
+    {
   if (ioctl(fd, SNDCTL_DSP_SAMPLESIZE, &tmp)<0 || tmp!=i)
     {
       /* Try the other one */
@@ -109,6 +152,7 @@ static int open_output(void)
       dpm.encoding ^= PE_16BIT;
       warnings=1;
     }
+    }
   if (dpm.encoding & PE_16BIT)
     dpm.encoding |= PE_SIGNED;
   else
@@ -163,6 +207,8 @@ static int open_output(void)
   /* Set buffer fragments (in extra_param[0]) */
   
   tmp=AUDIO_BUFFER_BITS;
+  if (luigi_driver)
+    tmp += 2;
   if (!(dpm.encoding & PE_MONO)) tmp++;
   if (dpm.encoding & PE_16BIT) tmp++;
   tmp |= (dpm.extra_param[0]<<16);
@@ -189,28 +235,35 @@ static int open_output(void)
   return warnings;
 }
 
+/* output_data comes from Luigi's linux_a.c.  This version seems to allow
+   for partial writes to the sound device, where as the original version
+   doesn't. */
 static void output_data(int32 *buf, int32 count)
 {
+  char *p;
+  int res, l;
+  
   if (!(dpm.encoding & PE_MONO)) count*=2; /* Stereo samples */
   
-  if (dpm.encoding & PE_16BIT)
-    {
+  if (dpm.encoding & PE_16BIT) {
       /* Convert data to signed 16-bit PCM */
       s32tos16(buf, count);
-      
-      /* Write the data out. Linux likes to give an EINTR if you suspend
-	 a program while waiting on a write, so we may need to retry. */
-      while ((-1==write(dpm.fd, buf, count * 2)) && errno==EINTR)
-	;
-    }
-  else
-    {
+      res = count*2;
+  } else {
       /* Convert to 8-bit unsigned and write out. */
       s32tou8(buf, count);
-      
-      while ((-1==write(dpm.fd, buf, count)) && errno==EINTR)
-	;
+      res = count;
+  }
+  for (p = (char *) buf; res > 0; res -= l) {
+again:
+    l = write(dpm.fd, p, res);
+    if (l < 0) {
+	if (errno == EINTR)
+		goto again;
+	return;
     }
+    p += l;
+  }
 }
 
 static void close_output(void)
