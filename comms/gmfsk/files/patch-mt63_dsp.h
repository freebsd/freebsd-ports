--- src/mt63/dsp.h.orig	Sat Sep 25 10:52:22 2004
+++ src/mt63/dsp.h	Sat Sep 25 10:58:58 2004
@@ -555,15 +555,15 @@
  inline void LowPass2(typeInp Inp, LowPass2elem &Elem,
 		typeW W1, typeW W2, typeW W5)
 { double Sum, Diff;
-  Sum=Elem.Mid+Elem.Out; Diff=Elem.Mid-Elem.Out; Elem.Mid+=W2*Inp-W1*Sum; Out+=W5*Diff; }
+  Sum=Elem.Mid+Elem.Out; Diff=Elem.Mid-Elem.Out; Elem.Mid+=W2*Inp-W1*Sum; Elem.Out+=W5*Diff; }
 
 template <class typeInp>
  inline void LowPass2(typeInp Inp, LowPass2elem &Elem, LowPass2weight &Weight)
 { double Sum, Diff;
   Sum=Elem.Mid+Elem.Out;
   Diff=Elem.Mid-Elem.Out;
-  Elem.Mid+=Weight.W2*Inp-Weigth.W1*Sum;
-  Out+=Weight.W5*Diff; }
+  Elem.Mid+=Weight.W2*Inp-Weight.W1*Sum;
+  Elem.Out+=Weight.W5*Diff; }
 
 /*
 inline void LowPass2(float Inp, double &Mid, double &Out,
