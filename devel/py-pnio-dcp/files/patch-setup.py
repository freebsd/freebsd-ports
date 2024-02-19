--- setup.py.orig	2023-10-04 11:20:39 UTC
+++ setup.py
@@ -30,7 +30,7 @@ classifiers = [
               ]
 
 setup(name="pnio_dcp",
-      use_scm_version={"local_scheme": "no-local-version"},
+      version='1.2.0',
       setup_requires=['setuptools_scm'],
       description='Discover and configure PROFINET devices with the PROFINET Discovery and basic Configuration Protocol (DCP) '
                   'protocol.',
