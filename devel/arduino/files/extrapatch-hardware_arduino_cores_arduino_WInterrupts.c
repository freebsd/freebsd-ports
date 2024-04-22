--- hardware/arduino/cores/arduino/WInterrupts.c.orig	2012-12-28 10:24:03.000000000 -0800
+++ hardware/arduino/cores/arduino/WInterrupts.c	2012-12-28 10:24:49.000000000 -0800
@@ -216,6 +216,21 @@
       #warning detachInterrupt may need some more work for this cpu (case 1)
     #endif
       break;
+
+#if defined(INT2)
+    case 2:
+    #if defined(EIMSK)
+      EIMSK &= ~(1 << INT2);
+    #elif defined(GICR)
+      GICR &= ~(1 << INT2);
+    #elif defined(GIMSK)
+      GIMSK &= ~(1 << INT2);
+    #else
+      #warning detachInterrupt may need some more work for this cpu (case 2)
+    #endif
+      break;
+#endif
+
 #endif
     }
       
