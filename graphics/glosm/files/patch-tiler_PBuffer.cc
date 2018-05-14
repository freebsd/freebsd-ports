--- tiler/PBuffer.cc.orig	2011-02-27 15:05:45 UTC
+++ tiler/PBuffer.cc
@@ -38,7 +38,7 @@ static bool CheckGLXVersion(Display* dis
 	return true;
 }
 
-PBuffer::PBuffer(int width, int height, int samples) : width_(width), height_(height), display_(NULL), context_(NULL), pbuffer_(NULL) {
+PBuffer::PBuffer(int width, int height, int samples) : width_(width), height_(height), display_(NULL), context_(NULL), pbuffer_(None) {
 	if ((display_ = XOpenDisplay(NULL)) == NULL)
 		throw PBufferException() << "cannot open default X display";
 
@@ -113,7 +113,7 @@ PBuffer::PBuffer(int width, int height, 
 }
 
 PBuffer::~PBuffer() {
-	if (!glXMakeCurrent(display_, NULL, NULL))
+	if (!glXMakeCurrent(display_, None, NULL))
 		warnx("cannot reset GLX context: glXMakeCurrent failed");
 	glXDestroyContext(display_, context_);
 	glXDestroyPbuffer(display_, pbuffer_);
