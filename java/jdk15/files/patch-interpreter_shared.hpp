$FreeBSD$

--- ../../hotspot/src/share/vm/interpreter/shared.hpp	22 Oct 2003 23:05:05 -0000	1.1.1.2
+++ ../../hotspot/src/share/vm/interpreter/shared.hpp	10 Oct 2004 05:03:55 -0000
@@ -41,19 +41,17 @@
 // to control the C++ namespace.
 class OptoReg VALUE_OBJ_CLASS_SPEC { 
  public:
-  enum Name {
-    // Chunk 0
+  typedef int Name;
 #ifdef COMPILER2
-    Physical = AdlcVMDeps::Physical, // Start of physical regs 
+  static const Name Physical = AdlcVMDeps::Physical; // Start of physical regs
 #endif
     // A few oddballs at the edge of the world
-    Special = -2,		// All special (not allocated) values
-    Bad = -1			// Not a register
-  };
+  static const Name Special = -2;	// All special (not allocated) values
+  static const Name Bad = -1;		// Not a register
 
   // Increment a register number.  As in:
   //    "for ( OptoReg::Name i; i=Control; i = add(i,1) ) ..."
-  static Name add( Name x, int y ) { return Name(x+y); }
+  static Name add( Name x, int y ) { return (x+y); }
 
   // (We would like to have an operator+ for RegName, but it is not
   // a class, so this would be illegal in C++.)
@@ -70,7 +68,7 @@
 // when we do not yet know how big the frame will be.
 class VMReg VALUE_OBJ_CLASS_SPEC { 
 public:
-  enum Name { };
+  typedef int Name;
 };
 
 
