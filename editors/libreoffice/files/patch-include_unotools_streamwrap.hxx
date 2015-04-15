--- include/unotools/streamwrap.hxx.orig	2014-12-11 21:00:24 UTC
+++ include/unotools/streamwrap.hxx
@@ -125,12 +125,12 @@ typedef ::cppu::ImplHelper1 <   ::com::s
 /** helper class for wrapping an SvStream into an com.sun.star.io::XOutputStream
     which is seekable (i.e. supports the com.sun.star.io::XSeekable interface).
 */
-class OSeekableOutputStreamWrapper
+class UNOTOOLS_DLLPUBLIC OSeekableOutputStreamWrapper
                 :public OOutputStreamWrapper
                 ,public OSeekableOutputStreamWrapper_Base
 {
 public:
-    UNOTOOLS_DLLPUBLIC OSeekableOutputStreamWrapper(SvStream& _rStream);
+    OSeekableOutputStreamWrapper(SvStream& _rStream);
 
 private:
     virtual ~OSeekableOutputStreamWrapper();
