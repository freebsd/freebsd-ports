--- lib/qwavheader.cc.orig	Fri Feb 23 21:29:12 2001
+++ lib/qwavheader.cc	Fri Feb 13 19:17:38 2004
@@ -5,6 +5,7 @@
 # include "qwavheader.hh"
 # include "qexception.hh"
 # include "qmisc.hh"
+# include "endian.hh"
 
 #ifdef NLS
   # include <locale.h>
@@ -15,12 +16,13 @@
 #endif
 
 
-const u_int32_t qwavheader::HEADERSIZE = sizeof(struct header);
+const u_int32_t qwavheader::HEADERSIZE = sizeof(struct wavheader);
 
 
-qwavheader::qwavheader (caddr_t p, u_int32_t wavlength=0) {
+qwavheader::qwavheader (caddr_t p, u_int32_t wavlength) {
 
-  header = (struct header *)p;
+  header = new wavheader(p);
+  mappedheader = (struct wavheader *)p;
 
   valid();
 
@@ -28,10 +30,14 @@
     validLength(wavlength);
 }
 
+qwavheader::~qwavheader()
+{
+  delete header;
+}
 
 void qwavheader::remap(caddr_t p) {
-
-  header = (struct header*)p;
+  mappedheader = (struct wavheader *)p;
+  header->headerCopy(p);
 }
 
 
@@ -41,6 +47,9 @@
   header->datalength = n*header->bytespersample;
   header->rifflength = header->datalength+36;
 
+  mappedheader->datalength = htolel(header->datalength);
+  mappedheader->rifflength = htolel(header->rifflength);
+
 #ifdef QVERBOSE
   cerr << "sample number set to " << n << endl;
 #endif
@@ -70,12 +79,6 @@
 }
 
 
-void qwavheader::write(caddr_t p) {
-
-  memmove(p,header,HEADERSIZE);
-}
-
-
 bool qwavheader::valid () {
     
   if (!strcmpn(header->riff,"RIFF",4) ||
@@ -164,4 +167,20 @@
 u_int32_t qwavheader::getBytesPerSample() { return header->bytespersample; }
 bool qwavheader::getStereo() { return header->channels==2; }
 
+void qwavheader::wavheader::headerCopy(caddr_t p)
+{
+  memmove(this, p, HEADERSIZE);
+
+#if __BYTE_ORDER != __LITTLE_ENDIAN
+  rifflength = letohl(rifflength);
+  fmtlength = letohl(fmtlength);
+  format = letohs(format);
+  channels = letohs(channels);
+  samplerate = letohl(samplerate);
+  bytespersec = letohl(bytespersec);
+  bytespersample = letohs(bytespersample);
+  bitspersample = letohs(bitspersample);
+  datalength = letohl(datalength);
+#endif
 
+}
