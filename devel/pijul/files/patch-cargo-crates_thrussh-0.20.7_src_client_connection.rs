error[E0382]: assign to part of moved value: `newkeys`
   --> .../cargo-crates/thrussh-0.20.7/src/client/connection.rs:550:13
    |
539 |             let mut newkeys = kexdhdone.compute_keys(
    |                 ----------- move occurs because `newkeys` has type `session::NewKeys`, which does not implement the `Copy` trait
...
549 |             session.0.kex = Some(Kex::NewKeys(newkeys));
    |                                               ------- value moved here
550 |             newkeys.sent = true;
    |             ^^^^^^^^^^^^^^^^^^^ value partially assigned here after move

error: aborting due to previous error

https://nest.pijul.com/pijul_org/thrussh/patches/AsyuWkJg4jAwNaG3H1yv1kbECx5E3GQAtjzXWBDB8yEGMswyfKbxKvYmAGWCohTVaTipdvF8mHh63yU5PTr5F9py

--- cargo-crates/thrussh-0.20.7/src/client/connection.rs.orig	2019-12-17 08:35:47 UTC
+++ cargo-crates/thrussh-0.20.7/src/client/connection.rs
@@ -546,8 +546,8 @@ impl<R: AsyncRead + AsyncWrite, H: Handler> Connection
                 &[msg::NEWKEYS],
                 &mut session.0.write_buffer,
             );
-            session.0.kex = Some(Kex::NewKeys(newkeys));
             newkeys.sent = true;
+            session.0.kex = Some(Kex::NewKeys(newkeys));
         }
         Ok(())
     }
