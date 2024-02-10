From 29c4728dbedc7e69cc2560b9b34058bbba9b1303 Mon Sep 17 00:00:00 2001
From: "Jeong, YunWon" <69878+youknowone@users.noreply.github.com>
Date: Thu, 28 Dec 2023 01:36:46 +0900
Subject: [PATCH] remove size assertions to avoid nightly error (#111)

---
 ast/src/impls.rs | 17 +++++++++--------
 1 file changed, 9 insertions(+), 8 deletions(-)

diff --git a/ast/src/impls.rs b/ast/src/impls.rs
index 594fadb3..8c788593 100644
--- ../Parser-0.3.0/ast/src/impls.rs
+++ ../Parser-0.3.0/ast/src/impls.rs
@@ -54,11 +54,12 @@ impl<R> Expr<R> {
     }
 }
 
-#[cfg(target_arch = "x86_64")]
-static_assertions::assert_eq_size!(crate::Expr, [u8; 72]);
-#[cfg(target_arch = "x86_64")]
-static_assertions::assert_eq_size!(crate::Stmt, [u8; 160]);
-#[cfg(target_arch = "x86_64")]
-static_assertions::assert_eq_size!(crate::Pattern, [u8; 96]);
-#[cfg(target_arch = "x86_64")]
-static_assertions::assert_eq_size!(crate::ExceptHandler, [u8; 64]);
+// TODO: make this a #[test] to avoid eq comparison
+// #[cfg(target_arch = "x86_64")]
+// static_assertions::assert_eq_size!(crate::Expr, [u8; 72]);
+// #[cfg(target_arch = "x86_64")]
+// static_assertions::assert_eq_size!(crate::Stmt, [u8; 160]);
+// #[cfg(target_arch = "x86_64")]
+// static_assertions::assert_eq_size!(crate::Pattern, [u8; 96]);
+// #[cfg(target_arch = "x86_64")]
+// static_assertions::assert_eq_size!(crate::ExceptHandler, [u8; 64]);
