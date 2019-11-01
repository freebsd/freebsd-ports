--- pdf-unicode.cc.orig	2019-10-27 19:19:18.837645000 +0000
+++ pdf-unicode.cc	2019-10-27 19:20:31.405700000 +0000
@@ -125,11 +125,11 @@
  * ===================
  */
 
-pdf::FullNFKC::FullNFKC(Unicode *unistr, int length)
+pdf::FullNFKC::FullNFKC(const Unicode *unistr, int length)
 : data(nullptr), length_(0)
 {
     assert(length >= 0);
-    this->data = unicodeNormalizeNFKC(unistr, length, &this->length_, nullptr);
+    this->data = unicodeNormalizeNFKC(const_cast<Unicode*>(unistr), length, &this->length_, nullptr);
 }
 
 pdf::FullNFKC::~FullNFKC()
@@ -141,7 +141,7 @@
  * ======================
  */
 
-pdf::MinimalNFKC::MinimalNFKC(Unicode *unistr, int length)
+pdf::MinimalNFKC::MinimalNFKC(const Unicode *unistr, int length)
 {
     this->string.append(unistr, length);
 }
