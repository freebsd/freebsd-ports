--- modules/lwjgl/shaderc/src/generated/java/org/lwjgl/util/shaderc/Shaderc.java.orig	2026-02-02 10:58:56 UTC
+++ modules/lwjgl/shaderc/src/generated/java/org/lwjgl/util/shaderc/Shaderc.java
@@ -19,7 +19,7 @@ public class Shaderc {
 
 public class Shaderc {
 
-    private static final SharedLibrary SHADERC = Library.loadNative(Shaderc.class, "org.lwjgl.shaderc", Configuration.SHADERC_LIBRARY_NAME.get(Platform.mapLibraryNameBundled("shaderc")), true);
+    private static final SharedLibrary SHADERC = Library.loadNative(Shaderc.class, "org.lwjgl.shaderc", Configuration.SHADERC_LIBRARY_NAME.get(Platform.mapLibraryNameBundled(Platform.get() == Platform.FREEBSD ? "shaderc_shared" : "shaderc")), Platform.get() != Platform.FREEBSD);
 
     /** Contains the function pointers loaded from the shaderc {@link SharedLibrary}. */
     public static final class Functions {
