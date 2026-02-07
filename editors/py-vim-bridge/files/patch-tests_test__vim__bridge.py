--- tests/test_vim_bridge.py.orig	2021-07-06 05:27:03 UTC
+++ tests/test_vim_bridge.py
@@ -80,7 +80,7 @@ class TestBridgedDecorator(unittest.TestCase):
         self.assertCodeEquals(vim.command.call_args[0][0], \
            """
            fun! Foo(x, y)
-           python << endp
+           python3 << endp
            __vim_brdg_3_x = vim.eval("a:x")
            __vim_brdg_3_y = vim.eval("a:y")
 
