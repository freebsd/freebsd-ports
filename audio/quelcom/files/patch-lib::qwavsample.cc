--- lib/qwavsample.cc.orig	Fri Feb 23 21:29:12 2001
+++ lib/qwavsample.cc	Fri Feb 13 19:17:38 2004
@@ -4,7 +4,7 @@
 
 # include "qwavsample.hh"
 # include "qexception.hh"
-
+# include "endian.hh"
 
 #ifdef NLS
   # include <locale.h>
@@ -21,11 +21,14 @@
 #endif
 
 
-qwavsample::qwavsample (qwav *wav, u_int32_t s=1) {
+qwavsample::qwavsample (qwav *wav, u_int32_t s) {
 
   sample = (union sample*) (wav->getMap()+wav->getOffset(s));
 
   if (wav->getBitsPerSample()==16) {
+	if ((int)sample % sizeof(int16_t) != 0)
+	  throw qexception(__PRETTY_FUNCTION__, _("misaligned 16-bit sample"));
+
     if (wav->getChannels()==2) {
       type = STEREO16;
     }
@@ -60,6 +63,8 @@
   sample = (union sample*) pointer;
   
   if (bitspersample==16) {
+	if ((int)sample % sizeof(int16_t) != 0)
+	  throw qexception(__PRETTY_FUNCTION__, _("misaligned 16-bit sample"));
     if (channels==2) {
       type = STEREO16;
       return;
@@ -88,7 +93,7 @@
 }
 
 
-qwavsample::qwavsample(caddr_t pointer, enum type t=STEREO16) {
+qwavsample::qwavsample(caddr_t pointer, enum type t) {
 
   sample = (union sample*) pointer;
   type = t;
@@ -99,9 +104,9 @@
   
   switch (type) {
     case MONO8: return sample->mono8;
-    case MONO16: return sample->mono16;
+    case MONO16: return letohs_s(sample->mono16);
     case STEREO8: return sample->stereo8.left;
-    case STEREO16: return sample->stereo16.left;
+    case STEREO16: return letohs_s(sample->stereo16.left);
   }
 
   throw qexception(__PRETTY_FUNCTION__,_("quelcom internal error"));
@@ -112,36 +117,36 @@
   
   switch (type) {
     case MONO8: return sample->mono8;
-    case MONO16: return sample->mono16;
+    case MONO16: return letohs_s(sample->mono16);
     case STEREO8: return sample->stereo8.right;
-    case STEREO16: return sample->stereo16.right;
+    case STEREO16: return letohs_s(sample->stereo16.right);
   }
   throw qexception(__PRETTY_FUNCTION__,_("quelcom internal error"));
 }
 
-void qwavsample::set(int left, int right=0) {
+void qwavsample::set(int left, int right) {
   
   switch (type) {
     case MONO8: sample->mono8=left; break;
-    case MONO16: sample->mono16=left; break;
+    case MONO16: sample->mono16=htoles_s(left); break;
     case STEREO8: sample->stereo8.left=left;sample->stereo8.right=right; break;
-    case STEREO16: sample->stereo16.left=left;sample->stereo16.right=right; break;
+    case STEREO16: sample->stereo16.left=htoles_s(left);sample->stereo16.right=htoles_s(right); break;
     default:
       throw qexception(__PRETTY_FUNCTION__,_("quelcom internal error"));
   }
 }
 
-bool qwavsample::isSilence(u_int32_t threshold=0) {
+bool qwavsample::isSilence(u_int32_t threshold) {
 
   switch (type) {
     case MONO8: return (u_int32_t)abs(sample->mono8)<=threshold;
-    case MONO16: return (u_int32_t)abs(sample->mono16)<=threshold;
+    case MONO16: return (u_int32_t)abs(letohs_s(sample->mono16))<=threshold;
     case STEREO8: 
       return ((u_int32_t)abs(sample->stereo8.left)<=threshold) && 
              ((u_int32_t)abs(sample->stereo8.right)<=threshold);
     case STEREO16:
-      return ((u_int32_t)abs(sample->stereo16.left)<=threshold) && 
-             ((u_int32_t)abs(sample->stereo16.right)<=threshold);
+      return ((u_int32_t)abs(letohs_s(sample->stereo16.left))<=threshold) && 
+             ((u_int32_t)abs(letohs_s(sample->stereo16.right))<=threshold);
   }
   throw qexception(__PRETTY_FUNCTION__,_("quelcom internal error"));
 }
@@ -173,10 +178,15 @@
 void qwavsample::print(ostream &os) {
 
   switch (type) {
-    case MONO8: os.form("(%d)",sample->mono8); break;
-    case MONO16: os.form("(%d)",sample->mono16); break;
-    case STEREO8: os.form("(%d,%d)",sample->stereo8.left,sample->stereo8.right); break;
-    case STEREO16: os.form("(%d,%d)",sample->stereo16.left,sample->stereo16.right); break;
+    case MONO8: os << '(' << sample->mono8 << ')'; break;
+    case MONO16: os << '(' << letohs_s(sample->mono16) << ')'; break;
+    case STEREO8:
+    	os << '(' << sample->stereo8.left << ',' << sample->stereo8.right << ')';
+	break;
+    case STEREO16:
+    	os << '(' << letohs_s(sample->stereo16.left) << ',' << letohs_s(sample->stereo16.right) << ')';
+	break;
+
     default:
       throw qexception(__PRETTY_FUNCTION__,_("quelcom internal error"));
   }
@@ -184,12 +194,16 @@
 
 
 void qwavsample::prod(double d) {
-
   switch (type) {
     case MONO8: sample->mono8*=d; break;
-    case MONO16: sample->mono16*=d; break;
+    case MONO16:
+	  sample->mono16 = htoles_s(short(letohs_s(sample->mono16)*d));
+	  break;
     case STEREO8: sample->stereo8.left*=d; sample->stereo8.right*=d; break;
-    case STEREO16: sample->stereo16.left*=d; sample->stereo16.right*=d; break;
+    case STEREO16:
+	  sample->stereo16.left = htoles_s(short(letohs_s(sample->stereo16.left)*d));
+	  sample->stereo16.right = htoles_s(short(letohs_s(sample->stereo16.right)*d));
+	  break;
     default:
       throw qexception(__PRETTY_FUNCTION__,_("quelcom internal error"));
   }
