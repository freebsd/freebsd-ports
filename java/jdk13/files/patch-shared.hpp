$FreeBSD$

--- ../../hotspot1.3.1/src/share/vm/interpreter/shared.hpp	11 Jul 2001 21:33:22 -0000	1.1.1.1
+++ ../../hotspot1.3.1/src/share/vm/interpreter/shared.hpp	22 Nov 2004 17:19:42 -0000
@@ -35,15 +35,13 @@
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
-    // A few oddballs at the edge of the world
-    Special = -2,		// All special (not allocated) values
-    Bad = -1			// Not a register
-  };
+  // A few oddballs at the edge of the world
+  static const Name Special = -2;	// All special (not allocated) values
+  static const Name Bad = -1;		// Not a register
 
   // Increment a register number.  As in:
   //    "for ( OptoReg::Name i; i=Control; i = add(i,1) ) ..."
@@ -64,7 +62,7 @@
 // when we do not yet know how big the frame will be.
 class VMReg VALUE_OBJ_CLASS_SPEC { 
 public:
-  enum Name { };
+  typedef int Name;
 };
 
 
