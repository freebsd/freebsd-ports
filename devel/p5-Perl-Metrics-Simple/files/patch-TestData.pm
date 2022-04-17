--- t/lib/Perl/Metrics/Simple/TestData.pm.orig	2021-03-21 15:14:01 UTC
+++ t/lib/Perl/Metrics/Simple/TestData.pm
@@ -121,12 +121,14 @@ sub make_test_data {
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
@@ -146,18 +148,21 @@ sub make_test_data {
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
