--- src/cuttlefish_escript.erl.orig	2015-05-20 11:41:20 UTC
+++ src/cuttlefish_escript.erl
@@ -34,7 +34,7 @@ cli_options() ->
 %% Option Name, Short Code, Long Code, Argument Spec, Help Message
 [
  {help,         $h, "help",        undefined,          "Print this usage page"},
- {etc_dir,      $e, "etc_dir",     {string, "/etc"},   "etc dir"},
+ {etc_dir,      $e, "etc_dir",     {string, "%%LOCALBASE%%/etc"},   "etc dir"},
  {dest_dir,     $d, "dest_dir",    string,             "specifies the directory to write the config file to"},
  {dest_file,    $f, "dest_file",   {string, "app"},    "the file name to write"},
  {schema_dir,   $s, "schema_dir",  string,             "a directory containing .schema files"},
