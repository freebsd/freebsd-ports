--- lgi/override/Gdk.lua.orig	2013-06-25 14:33:15.000000000 +0300
+++ lgi/override/Gdk.lua	2013-06-25 14:34:28.000000000 +0300
@@ -54,16 +54,18 @@
 } do Gdk._constant[name] = Gdk.Atom(val) end
 
 -- Easier-to-use Gdk.RGBA.parse() override.
-local parse = Gdk.RGBA.parse
-function Gdk.RGBA._method.parse(arg1, arg2)
-   if Gdk.RGBA:is_type_of(arg1) then
-      -- Standard member method.
-      return parse(arg1, arg2)
-   else
-      -- Static constructor variant.
-      local rgba = Gdk.RGBA()
-      return parse(rgba, arg1) and rgba or nil
-   end
+if Gdk.RGBA then
+    local parse = Gdk.RGBA.parse
+    function Gdk.RGBA._method.parse(arg1, arg2)
+       if Gdk.RGBA:is_type_of(arg1) then
+          -- Standard member method.
+          return parse(arg1, arg2)
+       else
+          -- Static constructor variant.
+          local rgba = Gdk.RGBA()
+          return parse(rgba, arg1) and rgba or nil
+       end
+    end
 end
 
 -- Gdk.Window.destroy() actually consumes 'self'.  Prepare workaround
