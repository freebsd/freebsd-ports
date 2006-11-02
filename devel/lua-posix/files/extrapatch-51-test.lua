--- test.lua.orig	Thu Nov  2 11:13:00 2006
+++ test.lua	Thu Nov  2 11:14:54 2006
@@ -41,7 +41,7 @@
 f"HOME"
 f"SHELL"
 f"absent"
-for k in ox.getenv() do io.write(k,"\t") end io.write"\n"
+for k,_ in pairs(ox.getenv()) do io.write(k,"\t") end io.write"\n"
 
 ------------------------------------------------------------------------------
 testing"putenv"
@@ -179,11 +179,11 @@
 ------------------------------------------------------------------------------
 testing"times"
 a=ox.times()
-for k,v in a do print(k,v) end
+for k,v in pairs(a) do print(k,v) end
 print"sleeping 10 seconds..."
 ox.sleep(10)
 b=ox.times()
-for k,v in b do print(k,v) end
+for k,v in pairs(b) do print(k,v) end
 print""
 print("elapsed",b.elapsed-a.elapsed)
 print("clock",os.clock())
