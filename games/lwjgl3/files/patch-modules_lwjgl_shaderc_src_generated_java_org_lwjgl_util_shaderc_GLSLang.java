--- modules/lwjgl/shaderc/src/generated/java/org/lwjgl/util/shaderc/GLSLang.java.orig	2026-02-02 10:58:56 UTC
+++ modules/lwjgl/shaderc/src/generated/java/org/lwjgl/util/shaderc/GLSLang.java
@@ -21,7 +21,7 @@ public class GLSLang {
 
 public class GLSLang {
 
-    private static final SharedLibrary SHADERC = Library.loadNative(GLSLang.class, "org.lwjgl.shaderc", Configuration.GLSLANG_LIBRARY_NAME, Shaderc::getLibrary);
+    private static final SharedLibrary SHADERC = Platform.get() == Platform.FREEBSD ? Library.loadNative(GLSLang.class, "org.lwjgl.shaderc", Configuration.GLSLANG_LIBRARY_NAME.get(Platform.mapLibraryNameBundled("glslang")), false) : Library.loadNative(GLSLang.class, "org.lwjgl.shaderc", Configuration.GLSLANG_LIBRARY_NAME, Shaderc::getLibrary);
 
     /** Contains the function pointers loaded from the shaderc {@link SharedLibrary}. */
     public static final class Functions {
