--- audio/drivers/alsamidi.h.orig	2022-01-29 22:16:06 UTC
+++ audio/drivers/alsamidi.h
@@ -47,7 +47,7 @@ class AlsaMidiDriver : public MidiDriver {
 
    public:
       AlsaMidiDriver(Seq* s);
-      virtual ~AlsaMidiDriver() {}
+      ~AlsaMidiDriver();
       virtual bool init();
       virtual Port registerOutPort(const QString& name);
       virtual Port registerInPort(const QString& name);
