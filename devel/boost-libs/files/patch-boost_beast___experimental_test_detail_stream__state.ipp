--- boost/beast/_experimental/test/detail/stream_state.ipp.orig	2026-04-15 14:38:52 UTC
+++ boost/beast/_experimental/test/detail/stream_state.ipp
@@ -108,7 +108,7 @@ remove() noexcept
 
     // If this goes off, it means the lifetime of a test::stream object
     // extended beyond the lifetime of the associated execution context.
-    BOOST_ASSERT(sp);
+    BOOST_ASSERT(static_cast<bool>(sp));
 
     sp->remove(*this);
 }
