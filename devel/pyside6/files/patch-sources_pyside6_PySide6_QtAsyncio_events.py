Fix stage.

Compiling '/wrkdirs/usr/ports/devel/pyside6/work-py311/stage/usr/local/lib/python3.11/site-packages/PySide6/QtAsyncio/events.py'...
***   File "/usr/local/lib/python3.11/site-packages/PySide6/QtAsyncio/events.py", line 601
    print(f"{context["message"]} from task {context["task"]._name},"+
                      ^^^^^^^
SyntaxError: f-string: unmatched '['

Regressed by: https://code.qt.io/cgit/pyside/pyside-setup.git/commit/?h=6.8.3&id=6aadd4a61d3cc363adeab7589d90e5faecf55f6e

--- sources/pyside6/PySide6/QtAsyncio/events.py.orig	2025-03-24 09:13:54 UTC
+++ sources/pyside6/PySide6/QtAsyncio/events.py
@@ -598,7 +598,7 @@ class QAsyncioEventLoop(asyncio.BaseEventLoop, QObject
     def default_exception_handler(self, context: dict[str, Any]) -> None:
         # TODO
         if context["message"]:
-            print(f"{context["message"]} from task {context["task"]._name},"+
+            print(f"{context['message']} from task {context['task']._name},"+
                     "read the following traceback:")
             print(context["traceback"])
 
