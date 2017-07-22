--- import/iz/containers.d	2017-04-03 03:39:24 UTC
+++ import/iz/containers.d
@@ -103,7 +103,7 @@ private:
     pragma(inline, true)
     void postblitElements()()
     {
-        static if (is(T == struct) && hasMember!(T, "__postblit") && isCopyable!T )
+        static if (is(T == struct) && hasMember!(T, "__postblit") && std.traits.isCopyable!T )
         {
             foreach(i; 0.._length)
                 (*rwPtr(i)).__postblit();
