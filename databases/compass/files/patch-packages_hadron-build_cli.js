diff --git a/packages/hadron-build/cli.js b/packages/hadron-build/cli.js
index d115de007..7d1ab09fe 100755
--- a/packages/hadron-build/cli.js
+++ b/packages/hadron-build/cli.js
@@ -16,7 +16,6 @@ const yargs = require('yargs')
   .command(require('./commands/verify'))
   .demand(1, 'Please specify a command.')
   .strict()
-  .env()
   .help('help')
   .fail(function(msg, err) {
     cli.abortIfError(err);
