--- cargo-crates/netdev-0.30.0/src/interface/unix.rs.orig	2024-12-27 16:28:59 UTC
+++ cargo-crates/netdev-0.30.0/src/interface/unix.rs
@@ -189,8 +189,8 @@ fn sockaddr_to_network_addr(sa: *mut libc::sockaddr) -
         if sa.is_null() {
             (None, None)
         } else if (*sa).sa_family as libc::c_int == libc::AF_LINK {
-            let nlen: i8 = (*sa).sa_data[3];
-            let alen: i8 = (*sa).sa_data[4];
+            let nlen: c_char = (*sa).sa_data[3];
+            let alen: c_char = (*sa).sa_data[4];
             if alen > 0 && alen as u8 + nlen as u8 + 8 <= (*sa).sa_len {
                 let ptr = (*sa).sa_data.as_mut_ptr();
                 let extended =
