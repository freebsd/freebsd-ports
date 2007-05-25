--- ../../hotspot/src/cpu/amd64/vm/register_amd64.hpp.orig	Tue Oct 19 14:41:27 2004
+++ ../../hotspot/src/cpu/amd64/vm/register_amd64.hpp	Thu May 24 15:50:42 2007
@@ -28,17 +28,17 @@
   int encoding() const
   { 
     assert(is_valid(), "invalid register"); 
-    return (int) this; 
+    return value(); 
   }
 
   bool is_valid() const
   {
-    return 0 <= (int) this && (int) this < number_of_registers;
+    return 0 <= value() && value() < number_of_registers;
   }
 
   bool has_byte_register() const
   {
-    return 0 <= (int) this && (int)this < number_of_byte_registers;
+    return 0 <= value() && value() < number_of_byte_registers;
   }
 
   const char* name() const;
@@ -92,12 +92,12 @@
   int encoding() const
   { 
     assert(is_valid(), "invalid fp register"); 
-    return (int) this; 
+    return value(); 
   }
 
   bool is_valid() const
   {
-    return 0 <= (int) this && (int) this < number_of_registers;
+    return 0 <= value() && value() < number_of_registers;
   }
 
   const char* name() const;
