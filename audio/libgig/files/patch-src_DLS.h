--- src/DLS.h.orig	2017-11-19 20:25:36 UTC
+++ src/DLS.h
@@ -517,8 +517,10 @@ namespace DLS {
             virtual ~File();
         protected:
             typedef std::list<Sample*>     SampleList;
+        public: // otherwise it breaks in build
             typedef std::list<Instrument*> InstrumentList;
 
+        protected:
             RIFF::File*              pRIFF;
             std::list<RIFF::File*>   ExtensionFiles;
             SampleList*              pSamples;
