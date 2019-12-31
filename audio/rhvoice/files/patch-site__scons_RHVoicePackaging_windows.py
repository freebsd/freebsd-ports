--- site_scons/RHVoicePackaging/windows.py.orig	2019-12-31 08:13:15 UTC
+++ site_scons/RHVoicePackaging/windows.py
@@ -19,7 +19,7 @@ import codecs
 import os.path
 from collections import OrderedDict
 import uuid
-from lxml import etree
+#from lxml import etree
 from .common import *
 
 uuid_namespace=uuid.UUID(hex="de5ba08b-8b9f-46e3-b0ee-d6bbac37017c")
