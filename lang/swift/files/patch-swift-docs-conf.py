--- swift/docs/conf.py.orig	2017-04-21 21:18:29.000000000 +0000
+++ swift/docs/conf.py	2018-01-22 12:34:17.478075000 +0000
@@ -29,7 +29,7 @@
 extensions = ['sphinx.ext.intersphinx', 'sphinx.ext.todo']
 
 # Add any paths that contain templates here, relative to this directory.
-templates_path = ['_templates']
+templates_path = ['_templates', 'archive']
 
 # The suffix of source filenames.
 source_suffix = '.rst'
@@ -146,7 +146,7 @@
 
 # Additional templates that should be rendered to pages, maps page names to
 # template names.
-html_additional_pages = {'LangRef': 'archive/LangRef.html'}
+html_additional_pages = {'archive/LangRef': 'LangRef.html'}
 
 # If false, no module index is generated.
 # html_domain_indices = True
