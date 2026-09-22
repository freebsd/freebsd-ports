--- packages/opencl/src/cl.pp	2023-10-28 12:54:09.078367000 -0500
+++ packages/opencl/src/cl.pp	2023-10-28 12:54:33.911516000 -0500
@@ -55,7 +55,7 @@
   OpenCLlib = 'OpenCL.dll';
   {$DEFINE extdecl := stdcall}
 {$ELSE}
-  {$IFDEF LINUX}
+  {$IF DEFINED(LINUX) OR DEFINED(FREEBSD)}
   {$DEFINE DYNLINK}
 const
   OpenCLlib = 'libOpenCL.so';
