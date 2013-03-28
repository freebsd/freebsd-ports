--- gaphor/services/componentregistry.py.orig
+++ gaphor/services/componentregistry.py
@@ -7,6 +7,7 @@
 """
 
 from zope import interface, component
+from zope.component import registry
 from gaphor.core import inject
 from gaphor.interfaces import IService, IEventFilter
 
@@ -27,7 +28,7 @@
         pass
 
     def init(self, app):
-        self._components = component.registry.Components(
+        self._components = registry.Components(
                                name='component_registry',
                                bases=(component.getGlobalSiteManager(),))
 
