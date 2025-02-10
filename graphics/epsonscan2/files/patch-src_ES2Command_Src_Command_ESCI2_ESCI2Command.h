--- src/ES2Command/Src/Command/ESCI2/ESCI2Command.h.orig	2024-09-12 07:10:31 UTC
+++ src/ES2Command/Src/Command/ESCI2/ESCI2Command.h
@@ -59,7 +59,7 @@ class CESCI2Command : public CCommandBase (protected)
     virtual bool IsFeedTypeADF() = 0;
     virtual bool IsAdfLoadSupported() = 0 ;
     virtual bool IsAutoCroppingEnabled() = 0;
- virtual bool IsAutoCroppingInscribedEnabled() = 0;
+    virtual bool IsAutoCroppingInscribedEnabled() = 0;
     virtual bool IsSkewCorrectionEnabled() =0;
     virtual ESNumber GetBackGroundRemoval() = 0;
 private:
