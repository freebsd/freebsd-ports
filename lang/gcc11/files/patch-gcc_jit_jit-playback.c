From 7510c23c1ec53aa4a62705f0384079661342ff7b Mon Sep 17 00:00:00 2001
From: Martin Liska <mliska@suse.cz>
Date: Wed, 24 Nov 2021 10:15:34 +0100
Subject: [PATCH 20/67] jit: Initialize function::m_blocks in ctor

This resolves the problem reported here:
https://mail.gnu.org/archive/html/bug-gnu-emacs/2021-11/msg00606.html
https://bugzilla.opensuse.org/show_bug.cgi?id=1192951

gcc/jit/ChangeLog:

	* jit-playback.c (function): Initialize m_blocks vector.
---
 gcc/jit/jit-playback.c | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

diff --git gcc/jit/jit-playback.c gcc/jit/jit-playback.c
index c6136301243..50db23df159 100644
--- gcc/jit/jit-playback.c
+++ gcc/jit/jit-playback.c
@@ -1481,7 +1481,8 @@ function (context *ctxt,
 : m_ctxt(ctxt),
   m_inner_fndecl (fndecl),
   m_inner_bind_expr (NULL),
-  m_kind (kind)
+  m_kind (kind),
+  m_blocks ()
 {
   if (m_kind != GCC_JIT_FUNCTION_IMPORTED)
     {
-- 
2.35.2

