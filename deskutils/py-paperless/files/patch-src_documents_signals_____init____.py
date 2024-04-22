--- src/documents/signals/__init__.py.orig	2024-02-22 18:57:58 UTC
+++ src/documents/signals/__init__.py
@@ -1,5 +1,5 @@
 from django.dispatch import Signal
 
-document_consumption_started = Signal(providing_args=["filename"])
-document_consumption_finished = Signal(providing_args=["document"])
-document_consumer_declaration = Signal(providing_args=[])
+document_consumption_started = Signal()
+document_consumption_finished = Signal()
+document_consumer_declaration = Signal()
