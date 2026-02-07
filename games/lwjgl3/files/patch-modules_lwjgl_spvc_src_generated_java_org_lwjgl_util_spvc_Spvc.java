--- modules/lwjgl/spvc/src/generated/java/org/lwjgl/util/spvc/Spvc.java.orig	2023-12-18 14:22:59 UTC
+++ modules/lwjgl/spvc/src/generated/java/org/lwjgl/util/spvc/Spvc.java
@@ -40,7 +40,7 @@ import static org.lwjgl.system.MemoryUtil.*;
  */
 public class Spvc {
 
-    private static final SharedLibrary SPVC = Library.loadNative(Spvc.class, "org.lwjgl.spvc", Configuration.SPVC_LIBRARY_NAME.get(Platform.mapLibraryNameBundled("spirv-cross")), true);
+    private static final SharedLibrary SPVC = Library.loadNative(Spvc.class, "org.lwjgl.spvc", Configuration.SPVC_LIBRARY_NAME.get(Platform.mapLibraryNameBundled(Platform.get() == Platform.FREEBSD ? "spirv-cross-c-shared" : "spirv-cross")), true);
 
     /** Contains the function pointers loaded from the spvc {@link SharedLibrary}. */
     public static final class Functions {
