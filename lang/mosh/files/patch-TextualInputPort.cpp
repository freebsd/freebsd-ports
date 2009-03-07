--- TextualInputPort.cpp.orig	2008-10-30 10:15:23.000000000 +0300
+++ TextualInputPort.cpp	2009-03-02 22:01:49.000000000 +0300
@@ -52,7 +52,7 @@
 TextualInputPort::TextualInputPort(BinaryInputPort* port, Transcoder* coder) : codec_(coder->codec()),
                                                                                port_(port),
                                                                                coder_(coder),
-                                                                               buffer_(NULL),
+                                                                               buffer_((const ucs4char*)NULL),
                                                                                line_(1),
                                                                                error_(Object::Nil),
                                                                                scanner_(new Scanner)
