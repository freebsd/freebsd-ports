--- src/std/lib/Cons.cpp.orig	Thu Feb 17 05:58:04 2005
+++ src/std/lib/Cons.cpp	Mon Feb 21 21:39:54 2005
@@ -153,7 +153,7 @@
     }
     // try to serialize the car
     if (p_car == nilp) {
-      os.write (Serial::SERIAL_NILP_ID);
+      os.write ((char)Serial::SERIAL_NILP_ID);
     } else {
       Serial* sobj = dynamic_cast <Serial*> (p_car);
       if (sobj == nilp) {
@@ -165,7 +165,7 @@
     }
     // try to serialize the cdr
     if (p_cdr == nilp) {
-      os.write (Serial::SERIAL_NILP_ID);
+      os.write ((char)Serial::SERIAL_NILP_ID);
     } else {
       Serial* sobj = dynamic_cast <Serial*> (p_cdr);
       if (sobj == nilp) {
