--- cpp/test/Slice/headers/run.py.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/Slice/headers/run.py
@@ -20,6 +20,9 @@ if len(path) == 0:
 sys.path.append(os.path.join(path[0], "scripts"))
 import TestUtil
 
+def execute(cmd):
+    return TestUtil.runCommand(cmd).wait()
+
 def clean():
     for f in ["iceslices",
               "linktoslices",
@@ -28,7 +31,7 @@ def clean():
               os.path.join("slices", "dir1", "linktoa3.ice")]:
         if os.path.exists(f):
             os.unlink(f)
-    os.system("rm -rf project1 tmp")
+    execute("rm -rf project1 tmp")
 
 clean()
 os.symlink("slices", "linktoslices")
@@ -44,7 +47,7 @@ slicedir = TestUtil.getSliceDir()
 os.symlink(slicedir, "iceslices")
 
 def runTest(cmd):
-    os.system(cmd)
+    execute(cmd)
     f = open("b.h")
     if not re.search('#include <dir1\/a1\.h>\n'
                      '#include <linktodir1\/a2\.h>\n'
@@ -72,9 +75,9 @@ if os.path.exists("SLICES"):
 #
 # Slice files are symlinks, include dir is a regular directory
 #
-os.system("mkdir -p project1/git/services.settings.slices")
-os.system("mkdir -p project1/src/services/settings")
-os.system("cd project1/src/services/settings &&  ln -s ../../../git/services.settings.slices slices")
+execute("mkdir -p project1/git/services.settings.slices")
+execute("mkdir -p project1/src/services/settings")
+execute("cd project1/src/services/settings &&  ln -s ../../../git/services.settings.slices slices")
 
 f = open("project1/git/services.settings.slices/A.ice", "w")
 f.write("// dumy file")
@@ -83,7 +86,7 @@ f = open("project1/git/services.settings.slices/B.ice"
 f.write("#include <services/settings/slices/A.ice>")
 f.close()
 
-os.system("cd project1 && %s -Isrc src/services/settings/slices/B.ice" % slice2cpp)
+execute("cd project1 && %s -Isrc src/services/settings/slices/B.ice" % slice2cpp)
 f = open("project1/B.h")
 
 if not re.search(re.escape('#include <services/settings/slices/A.h>'), f.read()):
@@ -95,16 +98,16 @@ clean()
 #
 # Slice file is regular file, include dir is a symlink to a second symlink
 #
-os.system("mkdir -p tmp/Ice-x.y.z/share")
-os.system("cd tmp/Ice-x.y.z/share && ln -s %s" % slicedir)
+execute("mkdir -p tmp/Ice-x.y.z/share")
+execute("cd tmp/Ice-x.y.z/share && ln -s %s" % slicedir)
 
 
-os.system("mkdir -p project1/share")
-os.system("cd project1/share && ln -s %s/tmp/Ice-x.y.z/share/slice" % basedir)
+execute("mkdir -p project1/share")
+execute("cd project1/share && ln -s %s/tmp/Ice-x.y.z/share/slice" % basedir)
 f = open("project1/A.ice", "w")
 f.write("#include <Ice/Identity.ice>")
 f.close()
-os.system("cd project1 && %s -Ishare/slice A.ice" % slice2cpp)
+execute("cd project1 && %s -Ishare/slice A.ice" % slice2cpp)
 f = open("project1/A.h")
 if not re.search(re.escape('#include <Ice/Identity.h>'), f.read()):
     print("failed!")
@@ -115,16 +118,16 @@ clean()
 #
 # Typical Ice install with symlink Ice-x.y -> Ice-x.y.z
 #
-os.system("mkdir -p tmp/Ice-x.y.z/slice/Ice")
-os.system("cd tmp && ln -s Ice-x.y.z Ice-x.y")
+execute("mkdir -p tmp/Ice-x.y.z/slice/Ice")
+execute("cd tmp && ln -s Ice-x.y.z Ice-x.y")
 f = open("tmp/Ice-x.y.z/slice/Ice/Identity.ice", "w")
 f.write("// dumy file")
 
-os.system("mkdir -p project1")
+execute("mkdir -p project1")
 f = open("project1/A.ice", "w")
 f.write("#include <Ice/Identity.ice>")
 f.close()
-os.system("cd project1 && %s -I%s/tmp/Ice-x.y/slice A.ice" % (slice2cpp, basedir))
+execute("cd project1 && %s -I%s/tmp/Ice-x.y/slice A.ice" % (slice2cpp, basedir))
 f = open("project1/A.h")
 if not re.search(re.escape('#include <Ice/Identity.h>'), f.read()):
     print("failed!")
