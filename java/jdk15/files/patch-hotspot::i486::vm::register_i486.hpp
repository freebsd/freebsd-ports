--- ../../hotspot/src/cpu/i486/vm/register_i486.hpp.orig	Thu May 24 15:27:42 2007
+++ ../../hotspot/src/cpu/i486/vm/register_i486.hpp	Thu May 24 19:51:43 2007
@@ -24,9 +24,9 @@
   static Register as_Register(int encoding)      { return (Register)encoding; }
 
   // accessors
-  int   encoding() const                         { assert(is_valid(), "invalid register"); return (int)this; }
-  bool  is_valid() const                         { return 0 <= (int)this && (int)this < number_of_registers; }
-  bool  has_byte_register() const                { return 0 <= (int)this && (int)this < number_of_byte_registers; }
+  int   encoding() const                         { assert(is_valid(), "invalid register"); return value(); }
+  bool  is_valid() const                         { return 0 <= value() && value() < number_of_registers; }
+  bool  has_byte_register() const                { return 0 <= value() && value() < number_of_byte_registers; }
   const char* name() const;
 };
 
@@ -74,8 +74,8 @@
   friend XMMRegister as_XMMRegister(int encoding) { return (XMMRegister)encoding; }
 
   // accessors
-  int   encoding() const                          { assert(is_valid(), "invalid register"); return (int)this; }
-  bool  is_valid() const                          { return 0 <= (int)this && (int)this < number_of_registers; }
+  int   encoding() const                          { assert(is_valid(), "invalid register"); return value(); }
+  bool  is_valid() const                          { return 0 <= value() && value() < number_of_registers; }
   const char* name() const;
 };
 
