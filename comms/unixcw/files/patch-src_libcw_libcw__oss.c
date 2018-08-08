--- src/libcw/libcw_oss.c.orig	2018-08-08 04:17:27 UTC
+++ src/libcw/libcw_oss.c
@@ -243,7 +243,7 @@ int cw_oss_open_device_internal(cw_gen_t
 	/* Get fragment size in bytes, may be different than requested
 	   with ioctl(..., SNDCTL_DSP_SETFRAGMENT), and, in particular,
 	   can be different than 2^N. */
-	if ((rv = ioctl(soundcard, (int) SNDCTL_DSP_GETBLKSIZE, &size)) == -1) {
+	if ((rv = ioctl(soundcard, SNDCTL_DSP_GETBLKSIZE, &size)) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl(SNDCTL_DSP_GETBLKSIZE): \"%s\"", strerror(errno));
 		close(soundcard);
@@ -322,7 +322,7 @@ int cw_oss_open_device_ioctls_internal(i
 #endif
 	/* Set the audio format to 8-bit unsigned. */
 	parameter = CW_OSS_SAMPLE_FORMAT;
-	if (ioctl(*fd, (int) SNDCTL_DSP_SETFMT, &parameter) == -1) {
+	if (ioctl(*fd, SNDCTL_DSP_SETFMT, &parameter) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl(SNDCTL_DSP_SETFMT): \"%s\"", strerror(errno));
 		return CW_FAILURE;
@@ -335,7 +335,7 @@ int cw_oss_open_device_ioctls_internal(i
 
 	/* Set up mono mode - a single audio channel. */
 	parameter = CW_AUDIO_CHANNELS;
-	if (ioctl(*fd, (int) SNDCTL_DSP_CHANNELS, &parameter) == -1) {
+	if (ioctl(*fd, SNDCTL_DSP_CHANNELS, &parameter) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl(SNDCTL_DSP_CHANNELS): \"%s\"", strerror(errno));
 		return CW_FAILURE;
@@ -352,7 +352,7 @@ int cw_oss_open_device_ioctls_internal(i
 	bool success = false;
 	for (int i = 0; cw_supported_sample_rates[i]; i++) {
 		rate = cw_supported_sample_rates[i];
-		if (!ioctl(*fd, (int) SNDCTL_DSP_SPEED, &rate)) {
+		if (!ioctl(*fd, SNDCTL_DSP_SPEED, &rate)) {
 			if (rate != cw_supported_sample_rates[i]) {
 				cw_debug_msg ((&cw_debug_object_dev), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_WARNING, "cw_oss: imprecise sample rate:");
 				cw_debug_msg ((&cw_debug_object_dev), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_WARNING, "cw_oss: asked for: %u", cw_supported_sample_rates[i]);
@@ -373,7 +373,7 @@ int cw_oss_open_device_ioctls_internal(i
 
 
 	audio_buf_info buff;
-	if (ioctl(*fd, (int) SNDCTL_DSP_GETOSPACE, &buff) == -1) {
+	if (ioctl(*fd, SNDCTL_DSP_GETOSPACE, &buff) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl(SNDCTL_DSP_GETOSPACE): \"%s\"", strerror(errno));
 		return CW_FAILURE;
@@ -402,7 +402,7 @@ int cw_oss_open_device_ioctls_internal(i
 	/* parameter = 0x7fff << 16 | CW_OSS_SETFRAGMENT; */
 	parameter = 0x0032 << 16 | CW_OSS_SETFRAGMENT;
 
-	if (ioctl(*fd, (int) SNDCTL_DSP_SETFRAGMENT, &parameter) == -1) {
+	if (ioctl(*fd, SNDCTL_DSP_SETFRAGMENT, &parameter) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl(SNDCTL_DSP_SETFRAGMENT): \"%s\"", strerror(errno));
 		return CW_FAILURE;
@@ -411,7 +411,7 @@ int cw_oss_open_device_ioctls_internal(i
 		      "cw_oss: fragment size is 2^%d = %d", parameter & 0x0000ffff, 2 << ((parameter & 0x0000ffff) - 1));
 
 	/* Query fragment size just to get the driver buffers set. */
-	if (ioctl(*fd, (int) SNDCTL_DSP_GETBLKSIZE, &parameter) == -1) {
+	if (ioctl(*fd, SNDCTL_DSP_GETBLKSIZE, &parameter) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl(SNDCTL_DSP_GETBLKSIZE): \"%s\"", strerror(errno));
 		return CW_FAILURE;
@@ -432,7 +432,7 @@ int cw_oss_open_device_ioctls_internal(i
         }
 #endif
 
-	if (ioctl(*fd, (int) SNDCTL_DSP_GETOSPACE, &buff) == -1) {
+	if (ioctl(*fd, SNDCTL_DSP_GETOSPACE, &buff) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl(SNDCTL_GETOSPACE): \"%s\"", strerror(errno));
 		return CW_FAILURE;
@@ -480,7 +480,7 @@ int cw_oss_get_version_internal(int fd, 
 	assert (fd);
 
 	int parameter = 0;
-	if (ioctl(fd, (int) OSS_GETVERSION, &parameter) == -1) {
+	if (ioctl(fd, OSS_GETVERSION, &parameter) == -1) {
 		cw_debug_msg ((&cw_debug_object), CW_DEBUG_SOUND_SYSTEM, CW_DEBUG_ERROR,
 			      "cw_oss: ioctl OSS_GETVERSION");
 		return CW_FAILURE;
