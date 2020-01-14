--- setup.py.orig	2019-01-12 15:15:42 UTC
+++ setup.py
@@ -39,7 +39,7 @@ from horizons.ext import polib
 # Ensure we are in the correct directory
 os.chdir(os.path.realpath(os.path.dirname(__file__)))
 
-if platform.dist()[0].lower() in ('debian', 'ubuntu'):
+if False:
 	executable_path = 'games'
 else:
 	executable_path = 'bin'
@@ -54,7 +54,7 @@ data = [
   (executable_path, ('unknown-horizons', )),
   ('share/pixmaps', ('content/packages/unknown-horizons.xpm', )),
   ('share/unknown-horizons', ('content/settings-template.xml', )),
-  ('share/man/man6', ('content/packages/unknown-horizons.6', )),
+  ('man/man6', ('content/packages/unknown-horizons.6', )),
 ]
 
 for root, dirs, files in [x for x in os.walk('content') if len(x[2])]:
@@ -136,13 +136,6 @@ class _build_i18n(distutils.cmd.Command):
 			targetpath = os.path.join("share/locale", lang, "LC_MESSAGES")
 			mo_files.append((targetpath, [mo_file]))
 
-		# Write translation stats to file and have it included in package
-		stats_filename = os.path.join('content', 'lang', 'stats.json')
-		with open(stats_filename, 'w') as f:
-			json.dump(translation_stats, f)
-
-		self.distribution.data_files.append((os.path.join('share', 'locale'), [stats_filename]))
-
 		return mo_files
 
 	def generate_atlases(self, size):
@@ -228,7 +221,7 @@ class _build_i18n(distutils.cmd.Command):
 				rmtree(os.path.join("content", "lang"))
 			copytree(os.path.join("build", "mo"), os.path.join("content", "lang"))
 
-		self.generate_atlases(2048)
+		#self.generate_atlases(2048)
 
 
 build.sub_commands.append(('build_i18n', None))
