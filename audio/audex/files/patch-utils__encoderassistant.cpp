--- ./utils/encoderassistant.cpp.orig	2009-06-10 05:24:03.000000000 -0400
+++ ./utils/encoderassistant.cpp	2009-06-10 05:24:41.000000000 -0400
@@ -44,7 +44,7 @@
     case EncoderAssistant::OGGENC : return (KProcess::execute(ENCODER_OGGENC_BIN, QStringList() << ENCODER_OGGENC_VERSION_PARA)==0);
     case EncoderAssistant::FLAC : return (KProcess::execute(ENCODER_FLAC_BIN, QStringList() << ENCODER_FLAC_VERSION_PARA)==0);
     case EncoderAssistant::FAAC : return (KProcess::execute(ENCODER_FAAC_BIN, QStringList() << ENCODER_FAAC_VERSION_PARA)==1);
-    case EncoderAssistant::WAVE : return (KProcess::execute(ENCODER_WAVE_BIN, QStringList() << ENCODER_WAVE_VERSION_PARA)==0);
+    case EncoderAssistant::WAVE : return TRUE;
     case EncoderAssistant::CUSTOM : return TRUE;
     default : return FALSE;
 
