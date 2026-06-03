--- modules/lwjgl/spvc/src/generated/java/org/lwjgl/util/spvc/Spvc.java.orig	2026-02-02 10:58:56 UTC
+++ modules/lwjgl/spvc/src/generated/java/org/lwjgl/util/spvc/Spvc.java
@@ -21,7 +21,7 @@ public class Spvc {
 
 public class Spvc {
 
-    private static final SharedLibrary SPVC = Library.loadNative(Spvc.class, "org.lwjgl.spvc", Configuration.SPVC_LIBRARY_NAME.get(Platform.mapLibraryNameBundled("spirv-cross")), true);
+    private static final SharedLibrary SPVC = Library.loadNative(Spvc.class, "org.lwjgl.spvc", Configuration.SPVC_LIBRARY_NAME.get(Platform.mapLibraryNameBundled(Platform.get() == Platform.FREEBSD ? "spirv-cross-c-shared" : "spirv-cross")), Platform.get() != Platform.FREEBSD);
 
     /** Contains the function pointers loaded from the spvc {@link SharedLibrary}. */
     public static final class Functions {
