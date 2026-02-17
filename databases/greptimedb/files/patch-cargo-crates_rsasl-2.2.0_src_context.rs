- fix bug that was fixed in rsasl-2.2.1

--- cargo-crates/rsasl-2.2.0/src/context.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/rsasl-2.2.0/src/context.rs
@@ -118,7 +118,8 @@ pub fn build_context<'a, 'b>(provider: &'a (dyn Provid
 }
 
 pub fn build_context<'a, 'b>(provider: &'a (dyn Provider<'b> + 'a)) -> &'a Context<'b> {
-    unsafe { &*(provider as *const dyn Provider as *const Context) }
+    // SAFETY: Context is repr(transparent) over Provider, so this transmute is safe
+    unsafe { core::mem::transmute::<&'a (dyn Provider<'b> + 'a), &'a Context<'b>>(provider) }
 }
 
 #[repr(transparent)]
