--- test/test.py.orig	2024-04-20 20:51:55 UTC
+++ test/test.py
@@ -17,7 +17,16 @@ from PIL import ImageDraw
 from StreamDeck.DeviceManager import DeviceManager
 from StreamDeck.ImageHelpers import PILHelper
 from PIL import ImageDraw
+import pytest
 
+def initialize_decks():
+    manager = DeviceManager(transport="dummy")
+    streamdecks = manager.enumerate()
+    return streamdecks
+
+@pytest.fixture(params=initialize_decks())
+def deck(request):
+    return request.param
 
 def test_pil_helpers(deck):
     if not deck.is_visual():
