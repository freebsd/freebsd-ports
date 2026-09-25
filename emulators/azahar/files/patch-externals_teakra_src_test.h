https://github.com/wwylele/teakra/pull/35

--- externals/teakra/src/test.h.orig	2018-12-21 16:34:51 UTC
+++ externals/teakra/src/test.h
@@ -31,7 +31,7 @@ static_assert(std::is_trivially_copyable_v<State>);
 
 struct TestCase {
     State before, after;
-    u16 opcode, expand;
+    u16 opcode, expand, unused;
 };
 
 static_assert(sizeof(TestCase) == 4312);
