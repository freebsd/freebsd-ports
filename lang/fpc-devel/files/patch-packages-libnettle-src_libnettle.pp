--- packages/libnettle/src/libnettle.pp	2023-10-28 12:47:25.745893000 -0500
+++ packages/libnettle/src/libnettle.pp	2023-10-28 12:52:31.472802000 -0500
@@ -51,7 +51,7 @@
   NettleExternal_library='nettle';
   HogweedExternal_library='hogweed';
 
-{$ifdef linux}
+{$if defined(linux) or defined(freebsd)}
   NettleLibraryFileName = 'lib'+NettleExternal_library+'.so';
   HogweedLibraryFileName = 'lib'+HogweedExternal_library+'.so';
 {$else}
