based on https://github.com/dankamongmen/libdank/blob/master/libdank/compat-FreeBSD.c
--- usb_stream/pcm_usb_stream.c.orig	2024-06-10 09:18:39 UTC
+++ usb_stream/pcm_usb_stream.c
@@ -77,6 +77,69 @@ static pthread_mutex_t uus_mutex = PTHREAD_MUTEX_INITI
 static struct user_usb_stream *uus;
 static pthread_mutex_t uus_mutex = PTHREAD_MUTEX_INITIALIZER;
 
+#ifndef __linux__
+/*
+ * Copyright (c) 2000-2011, Nick Black et al
+ * All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions are met:
+ *     * Redistributions of source code must retain the above copyright
+ *       notice, this list of conditions and the following disclaimer.
+ *     * Redistributions in binary form must reproduce the above copyright
+ *       notice, this list of conditions and the following disclaimer in the
+ *       documentation and/or other materials provided with the distribution.
+ *     * Neither the name of Nick Black nor the names of other contributors may              
+ * be used to endorse or promote products derived from this software
+ * without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
+ * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
+ * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <copyright
+ * holder> BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
+ * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
+ * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
+ * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
+ * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
+ * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
+ * POSSIBILITY OF SUCH DAMAGE.
+ */
+
+// This is suitable really only for use with libdank's mremap_and_ftruncate(),
+// due to assumptions it makes about the flags to pass to mmap(2). The only
+// mremap(2) use case addressed is that of MREMAP_MAYMOVE. oldaddr must be a
+// valid previous return from mmap(); NULL is not acceptable (ala Linux's
+// mremap(2)), resulting in undefined behavior, despite realloc(3) semantics.
+// Similarly, oldlen and newlen must be non-zero (and page-aligned).
+void *mremap_compat(int fd,void *oldaddr,size_t oldlen,
+               size_t newlen,int prot,int flags){
+   void *ret;
+
+   // From mmap(2) on freebsd 6.3: A successful FIXED mmap deletes any
+   // previous mapping in the allocated address range. This means:
+   // remapping over a current map will blow it away (unless FIXED isn't
+   // provided, in which case it can't overlap an old mapping. See bug
+   // 733 for extensive discussion of this issue for Linux and FreeBSD).
+   if((ret = mmap((char *)oldaddr + oldlen,newlen - oldlen,prot,flags,fd,oldlen)) == MAP_FAILED){
+       // We couldn't get the memory whatsoever (or we were a fresh
+       // allocation that succeeded). Return the immediate result...
+       return ret;
+   } // ret != MAP_FAILED. Did we squash?
+   if(ret != (char *)oldaddr + oldlen){
+       // We got the memory, but not where we wanted it. Copy over the
+       // old map, and then free it up...
+       munmap(ret,newlen - oldlen);
+       if((ret = mmap(NULL,newlen,prot,flags,fd,0)) == MAP_FAILED){
+           return ret;
+       }
+       memcpy(ret,oldaddr,oldlen);
+       munmap(oldaddr,oldlen); // Free the old mapping
+       return ret;
+   } // We successfully squashed. Return a pointer to the first buf.
+   return oldaddr;
+}
+#endif
+
 static struct user_usb_stream *get_uus(int card)
 {
 	pthread_mutex_lock(&uus_mutex);
@@ -217,7 +280,11 @@ static int snd_pcm_us_prepare(snd_pcm_ioplug_t *io)
 		}
 
 
+#ifdef __linux__
 		uus->s = mremap(uus->s, sizeof(struct usb_stream), uus->s->read_size, MREMAP_MAYMOVE);
+#else
+		uus->s = mremap_compat(us->pfd.fd, uus->s, sizeof(struct usb_stream), uus->s->read_size, PROT_READ, MAP_SHARED);
+#endif
 		if (MAP_FAILED == uus->s) {
 			perror("ALSA/USX2Y: mmap");
 			return -EPERM;
