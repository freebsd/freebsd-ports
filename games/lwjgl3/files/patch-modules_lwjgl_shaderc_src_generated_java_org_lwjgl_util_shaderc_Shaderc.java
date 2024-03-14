--- modules/lwjgl/shaderc/src/generated/java/org/lwjgl/util/shaderc/Shaderc.java.orig	2023-12-18 14:22:59 UTC
+++ modules/lwjgl/shaderc/src/generated/java/org/lwjgl/util/shaderc/Shaderc.java
@@ -20,7 +20,7 @@ import static org.lwjgl.system.MemoryUtil.*;
 /** Native bindings to the libshaderc C API of the <a href="https://github.com/google/shaderc/">shaderc</a> library. */
 public class Shaderc {
 
-    private static final SharedLibrary SHADERC = Library.loadNative(Shaderc.class, "org.lwjgl.shaderc", Configuration.SHADERC_LIBRARY_NAME.get(Platform.mapLibraryNameBundled("shaderc")), true);
+    private static final SharedLibrary SHADERC = Library.loadNative(Shaderc.class, "org.lwjgl.shaderc", Configuration.SHADERC_LIBRARY_NAME.get(Platform.mapLibraryNameBundled(Platform.get() == Platform.FREEBSD ? "shaderc_shared" : "shaderc")), true);
 
     /** Contains the function pointers loaded from the shaderc {@link SharedLibrary}. */
     public static final class Functions {
