--- multiqc/utils/config.py.orig	2019-09-22 13:24:47 UTC
+++ multiqc/utils/config.py
@@ -42,13 +42,13 @@ MULTIQC_DIR = os.path.dirname(os.path.realpath(inspect
 # Default MultiQC config
 searchp_fn = os.path.join( MULTIQC_DIR, 'utils', 'config_defaults.yaml')
 with open(searchp_fn) as f:
-    configs = yaml.load(f)
+    configs = yaml.load(f, Loader=yaml.FullLoader)
     for c, v in configs.items():
         globals()[c] = v
 # Module filename search patterns
 searchp_fn = os.path.join( MULTIQC_DIR, 'utils', 'search_patterns.yaml')
 with open(searchp_fn) as f:
-    sp = yaml.load(f)
+    sp = yaml.load(f, Loader=yaml.FullLoader)
 
 # Other defaults that can't be set in YAML
 data_tmp_dir = '/tmp' # will be overwritten by core script
@@ -118,7 +118,7 @@ def mqc_load_config(yaml_config):
     if os.path.isfile(yaml_config):
         try:
             with open(yaml_config) as f:
-                new_config = yaml.load(f)
+                new_config = yaml.load(f, Loader=yaml.FullLoader)
                 logger.debug("Loading config settings from: {}".format(yaml_config))
                 mqc_add_config(new_config, yaml_config)
         except (IOError, AttributeError) as e:
@@ -132,11 +132,11 @@ def mqc_load_config(yaml_config):
 def mqc_cl_config(cl_config):
     for clc_str in cl_config:
         try:
-            parsed_clc = yaml.load(clc_str)
+            parsed_clc = yaml.load(clc_str, Loader=yaml.FullLoader)
             # something:var fails as it needs a space. Fix this (a common mistake)
             if isinstance(parsed_clc, str) and ':' in clc_str:
                 clc_str = ': '.join(clc_str.split(':'))
-                parsed_clc = yaml.load(clc_str)
+                parsed_clc = yaml.load(clc_str, Loader=yaml.FullLoader)
             assert(isinstance(parsed_clc, dict))
         except yaml.scanner.ScannerError as e:
             logger.error("Could not parse command line config: {}\n{}".format(clc_str, e))
