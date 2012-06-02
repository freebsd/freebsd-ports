--- horizons/savegamemanager.py.orig	2012-05-26 22:01:19.000000000 +0400
+++ horizons/savegamemanager.py	2012-05-26 22:02:27.000000000 +0400
@@ -370,7 +370,7 @@
 	def get_campaign_status(cls):
 		"""Read the campaign status from the saved YAML file"""
 		if os.path.exists(cls.campaign_status_file):
-			return YamlCache.get_yaml_file(cls.campaign_status_file)
+			return YamlCache.get_file(cls.campaign_status_file)
 		return {}
 
 	@classmethod
