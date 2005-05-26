--- Makefile.PL.orig	Sat Apr 30 01:18:38 2005
+++ Makefile.PL	Sat Apr 30 01:20:53 2005
@@ -23,4 +23,9 @@
 	IO::Scalar => 0,
 	File::Temp => 0.12,
     },
+    'MAN3PODS' => {
+	'lib/Log/Dispatch/Config.pm' => 'blib/man3/Log::Dispatch::Config.3',
+	'lib/Log/Dispatch/Configurator.pm' => 'blib/man3/Log::Dispatch::Configurator.3',
+	'lib/Log/Dispatch/Configurator/AppConfig.pm' => 'blib/man3/Log::Dispatch::Configurator::AppConfig.3',
+    },
 );
