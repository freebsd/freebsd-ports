--- src/paperless/urls.py.orig	2024-02-22 19:09:18 UTC
+++ src/paperless/urls.py
@@ -1,5 +2,6 @@
 from django.conf import settings
-from django.conf.urls import include, static, url
+from django.conf.urls import include, static
+from django.urls import re_path
 from django.contrib import admin
 from django.urls import reverse_lazy
 from django.views.decorators.csrf import csrf_exempt
@@ -27,32 +27,32 @@ router.register(r"tags", TagViewSet)
 urlpatterns = [
 
     # API
-    url(
+    re_path(
         r"^api/auth/",
         include(
             ('rest_framework.urls', 'rest_framework'),
             namespace="rest_framework")
     ),
-    url(r"^api/", include((router.urls, 'drf'), namespace="drf")),
+    re_path(r"^api/", include((router.urls, 'drf'), namespace="drf")),
 
     # File downloads
-    url(
+    re_path(
         r"^fetch/(?P<kind>doc|thumb)/(?P<pk>\d+)$",
         FetchView.as_view(),
         name="fetch"
     ),
 
     # File uploads
-    url(r"^push$", csrf_exempt(PushView.as_view()), name="push"),
+    re_path(r"^push$", csrf_exempt(PushView.as_view()), name="push"),
 
     # Favicon
-    url(r"^favicon.ico$", FaviconView.as_view(), name="favicon"),
+    re_path(r"^favicon.ico$", FaviconView.as_view(), name="favicon"),
 
     # The Django admin
-    url(r"admin/", admin.site.urls),
+    re_path(r"admin/", admin.site.urls),
 
     # Redirect / to /admin
-    url(r"^$", RedirectView.as_view(
+    re_path(r"^$", RedirectView.as_view(
         permanent=True, url=reverse_lazy("admin:index"))),
 
 ] + static.static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
