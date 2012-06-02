--- horizons/util/yamlcache.py.orig	2012-05-26 21:52:18.000000000 +0400
+++ horizons/util/yamlcache.py	2012-05-26 21:57:18.000000000 +0400
@@ -82,11 +82,6 @@
 
 	@classmethod
 	def get_file(cls, filename, game_data=False):
-		data = cls.get_yaml_file(filename, game_data=game_data)
-		return data
-
-	@classmethod
-	def get_yaml_file(cls, filename, game_data=False):
 		# calc the hash
 		f = open(filename, 'r')
 		h = hash(f.read())
@@ -98,7 +93,7 @@
 		if isinstance(filename, unicode):
 			filename = filename.encode('utf8') # shelve needs str keys
 
-		def handle_get_yaml_file_error(e, release):
+		def handle_get_file_error(e, release):
 				# when something unexpected happens, shelve does not guarantee anything.
 				# since crashing on any access is part of the specified behaviour, we need to handle it.
 				# cf. http://bugs.python.org/issue14041
@@ -108,12 +103,12 @@
 				cls.cache = None
 				if release:
 					cls.lock.release()
-				return cls.get_yaml_file(filename, game_data=game_data)
+				return cls.get_file(filename, game_data=game_data)
 
 		try:
 			yaml_file_in_cache = (filename in cls.cache and cls.cache[filename][0] == h)
 		except Exception as e:
-			return handle_get_yaml_file_error(e, release=False)
+			return handle_get_file_error(e, release=False)
 
 		if not yaml_file_in_cache:
 			data = yaml.load( f, Loader = SafeLoader )
@@ -131,7 +126,7 @@
 			try:
 				cls.cache[filename] = (h, data)
 			except Exception as e:
-				return handle_get_yaml_file_error(e, release=True)
+				return handle_get_file_error(e, release=True)
 
 			if not cls.sync_scheduled:
 				cls.sync_scheduled = True
