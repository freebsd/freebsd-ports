--- letters-trans.py.orig	Tue Jun 29 10:42:05 2004
+++ letters-trans.py	Wed Jul  7 11:28:25 2004
@@ -60,7 +60,8 @@
     sys.exit(0)
         
 # get description names from memory assetml, these are the words used by letters.py
-parser = pyassetml.AssetmlParser('childsplay/memory-136x136/memory-136x136.assetml')
+assetmlfile = os.path.join(cwd,'memory-136x136.assetml')
+parser = pyassetml.AssetmlParser(assetmlfile)
 loc = parser.get_locale()# get current locale setting, only the first two chars !!
 wlist_org = parser.find_names((('file','.'),('description',"en")))
 wlist = parser.find_names((('file','.'),('description',loc)))
