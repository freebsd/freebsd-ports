--- Build.PL.orig	2022-12-08 23:24:31 UTC
+++ Build.PL
@@ -127,7 +127,6 @@ my $build = Module::Build->new(
   },
 
   add_to_cleanup => ['t/Sample/pod2htm*'],
-  script_files   => ['bin/config_data'],
   meta_merge     => {
     resources => {
       MailingList => 'mailto:module-build@perl.org',
