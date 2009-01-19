--- brainworkshop.pyw.orig	2009-01-17 21:01:40.000000000 +0300
+++ brainworkshop.pyw	2009-01-19 22:41:15.000000000 +0300
@@ -49,9 +49,7 @@
         hasattr(sys, "importers") # old py2exe
         or imp.is_frozen("__main__")) # tools/freeze
 def get_main_dir():
-    if main_is_frozen():
-        return os.path.dirname(sys.executable)
-    return sys.path[0]    
+    return '/'
 def get_data_dir():
     try:
         return sys.argv[sys.argv.index('--datadir') + 1]
@@ -355,6 +353,9 @@
 except:
     pass
 
+if not os.path.exists(FOLDER_DATA):
+    os.mkdir(FOLDER_DATA)
+
 if not os.path.isfile(os.path.join(get_data_dir(), CONFIGFILE)):
     newconfigfile = open(os.path.join(os.path.join(get_data_dir(), CONFIGFILE)), 'w')
     newconfigfile.write(CONFIGFILE_DEFAULT_CONTENTS)
@@ -643,17 +644,7 @@
     print >> sys.stderr, ''.join(str_list)
     sys.exit(1)
 
-if USE_MUSIC:
-    try:
-        from pyglet.media import avbin
-    except:
-        USE_MUSIC = False
-        str_list = []
-        str_list.append('\nAVBin not detected. Music disabled.\n')
-        str_list.append('Download AVBin from: http://code.google.com/p/avbin/\n\n')
-        #str_list.append(str(sys.exc_info()))
-        #print >> sys.stderr, ''.join(str_list)
-        print ''.join(str_list)
+USE_MUSIC = False
     
 # Initialize resources (sounds and images)
 #
