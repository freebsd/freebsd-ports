--- modules/lwjgl/shaderc/src/generated/java/org/lwjgl/util/shaderc/GLSLangResourceLimits.java.orig	2026-02-02 10:58:56 UTC
+++ modules/lwjgl/shaderc/src/generated/java/org/lwjgl/util/shaderc/GLSLangResourceLimits.java
@@ -18,7 +18,7 @@ public class GLSLangResourceLimits {
 
 public class GLSLangResourceLimits {
 
-    private static final SharedLibrary SHADERC = Library.loadNative(GLSLangResourceLimits.class, "org.lwjgl.shaderc", Configuration.GLSLANG_RESOURCE_LIBRARY_NAME, Shaderc::getLibrary);
+    private static final SharedLibrary SHADERC = Platform.get() == Platform.FREEBSD ? Library.loadNative(GLSLangResourceLimits.class, "org.lwjgl.shaderc", Configuration.GLSLANG_RESOURCE_LIBRARY_NAME.get(Platform.mapLibraryNameBundled("glslang-default-resource-limits")), false) : Library.loadNative(GLSLangResourceLimits.class, "org.lwjgl.shaderc", Configuration.GLSLANG_RESOURCE_LIBRARY_NAME, Shaderc::getLibrary);
 
     /** Contains the function pointers loaded from the shaderc {@link SharedLibrary}. */
     public static final class Functions {
