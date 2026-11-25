Description: Drop the data_files entry that installs the JavaScript files
  as a top-level static/ directory under the install prefix (outside
  site-packages with pep517). The files are already installed as package
  data in celery_progress/static/celery_progress/, where Django's
  AppDirectoriesFinder looks for them.
Issue ID: https://github.com/czue/celery-progress/pull/120

--- setup.py.orig	2025-01-30 07:16:10 UTC
+++ setup.py
@@ -47,9 +47,6 @@ setup(
         'Topic :: Internet :: WWW/HTTP',
         'Topic :: Internet :: WWW/HTTP :: Dynamic Content',
     ],
-    data_files=[
-        ('static/celery_progress', glob('celery_progress/static/celery_progress/*', recursive=True)),
-    ],
     extras_require={
         'websockets': ['channels'],
         'redis': ['channels_redis'],
