--- t/lib/Perl/Metrics/Simple/TestData.pm.orig	2012-04-22 22:39:58.229109428 +0900
+++ t/lib/Perl/Metrics/Simple/TestData.pm	2012-04-22 22:41:19.361852783 +0900
@@ -127,12 +127,14 @@
                     name              => 'foo',
                     lines             => 1,
                     mccabe_complexity => 1,
+                    line_number       => 10,
                     path              => "$test_directory/subs_no_package.pl",
                 },
                 {
                     name              => 'bar',
                     lines             => 2,
                     mccabe_complexity => 1,
+                    line_number       => 11,
                     path              => "$test_directory/subs_no_package.pl",
                 }
             ],
@@ -152,18 +154,21 @@
                     name              => 'new',
                     lines             => 5,
                     mccabe_complexity => 1,
+                    line_number       => 8,
                     path => "$test_directory/Perl/Code/Analyze/Test/Module.pm",
                 },
                 {
                     name              => 'foo',
                     lines             => 9,
                     mccabe_complexity => 8,
+                    line_number       => 14,
                     path => "$test_directory/Perl/Code/Analyze/Test/Module.pm",
                 },
                 {
                     name              => 'say_hello',
                     lines             => 9,
                     mccabe_complexity => 5,
+                    line_number       => 26,
                     path => "$test_directory/Perl/Code/Analyze/Test/Module.pm",
                 },
             ],
