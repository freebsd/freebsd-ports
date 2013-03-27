--- setup.py.orig	2012-01-11 23:54:57.000000000 +0100
+++ setup.py	2013-03-24 09:52:46.000000000 +0100
@@ -44,7 +44,7 @@
 
 include_dirs = []
 library_dirs = []
-libraries = ['geos','geos_c','proj']
+libraries = ['geos','geos_c','proj','iconv']
 runtime_library_dirs = []
 extra_objects = []
 define_macros = []
@@ -86,29 +86,30 @@
 
 def get_amalgamation():
     """Download the Spatialite amalgamation if it isn't there, already."""
-    if os.path.exists(AMALGAMATION_ROOT):
-        return
-    os.mkdir(AMALGAMATION_ROOT)
-    print "Downloading amalgation."
-
-    # find out what's current amalgamation ZIP file
-    download_page = urllib.urlopen("https://www.gaia-gis.it/fossil/libspatialite/index").read()
-    pattern = re.compile("(libspatialite-amalgamation.*?\.zip)")
-    download_file = pattern.findall(download_page)[0]
-    amalgamation_url = "http://www.gaia-gis.it/gaia-sins/" + download_file
-    zip_dir = string.replace(download_file,'.zip','')
-    # and download it
-    urllib.urlretrieve(amalgamation_url, "tmp.zip")
-
-    zf = zipfile.ZipFile("tmp.zip")
-    files = ["sqlite3.c", "headers/spatialite/sqlite3.h", "spatialite.c", "headers/spatialite/sqlite3ext.h","headers/spatialite/spatialite.h","headers/spatialite/gaiaaux.h","headers/spatialite/gaiaexif.h","headers/spatialite/gaiageo.h"]
-    for fn in files:
-        print "Extracting", fn
-        outf = open(AMALGAMATION_ROOT + os.sep + string.split(fn,'/')[-1], "wb")
-        outf.write(zf.read(zip_dir + '/' + fn))
-        outf.close()
-    zf.close()
-    os.unlink("tmp.zip")
+#   into ${FILESDIR} for FreeBSD
+#    if os.path.exists(AMALGAMATION_ROOT):
+#        return
+#    os.mkdir(AMALGAMATION_ROOT)
+#    print "Downloading amalgation."
+#
+#    # find out what's current amalgamation ZIP file
+#    download_page = urllib.urlopen("http://www.gaia-gis.it/gaia-sins/libspatialite-sources/").read()
+#    pattern = re.compile("(libspatialite-amalgamation.*?\.zip)")
+#    download_file = pattern.findall(download_page)[-1]
+#    amalgamation_url = "http://www.gaia-gis.it/gaia-sins/libspatialite-sources/" + download_file
+#    zip_dir = string.replace(download_file,'.zip','')
+#    # and download it
+#    urllib.urlretrieve(amalgamation_url, "tmp.zip")
+#
+#    zf = zipfile.ZipFile("tmp.zip")
+#    files = ["sqlite3.c", "headers/spatialite/sqlite3.h", "spatialite.c", "headers/spatialite/sqlite3ext.h","headers/spatialite/spatialite.h","headers/spatialite/gaiaaux.h","headers/spatialite/gaiaexif.h","headers/spatialite/gaiageo.h"]
+#    for fn in files:
+#        print "Extracting", fn
+#        outf = open(AMALGAMATION_ROOT + os.sep + string.split(fn,'/')[-1], "wb")
+#        outf.write(zf.read(zip_dir + '/' + fn))
+#        outf.close()
+#    zf.close()
+#    os.unlink("tmp.zip")
 
 class MyBuildExt(build_ext):
 
@@ -119,8 +120,10 @@
           ext.libraries.append("iconv")
 
         #Default locations for Mac
+        ext.include_dirs.append("%%LOCALBASE%%/include/")
         ext.include_dirs.append("/Library/Frameworks/GEOS.framework/unix/include/")
         ext.include_dirs.append("/Library/Frameworks/PROJ.framework/unix/include/")
+        ext.library_dirs.append("%%LOCALBASE%%/lib")
         ext.library_dirs.append("/Library/Frameworks/GEOS.framework/unix/lib")
         ext.library_dirs.append("/Library/Frameworks/PROJ.framework/unix/lib")
 
@@ -132,7 +135,7 @@
         ext.sources.append(os.path.join(AMALGAMATION_ROOT, "spatialite.c"))
         ext.include_dirs.append(AMALGAMATION_ROOT)
         build_ext.build_extension(self, ext)
-        
+
 
 #    def __setattr__(self, k, v):
 #        # Make sure we don't link against the SQLite library, no matter what setup.cfg says
