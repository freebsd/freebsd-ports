commit 01764b0eb3c7b7407f3119ef711d5b07d7b9a313
Author: Jean-Baptiste Mardelle <jb@kdenlive.org>
Date:   Fri Oct 24 13:22:36 2014 +0200

    Fix filtering of mailing-list based on "List-id".
    BUG:339090
    FIXED-IN: 4.14.3
    CCBUG:339090

--- mailcommon/search/searchpattern.cpp
+++ mailcommon/search/searchpattern.cpp
@@ -672,7 +672,6 @@ SearchRule::RequiredPart SearchRuleString::requiredPart() const
          kasciistricmp( f, "<status>" ) == 0 ||
          kasciistricmp( f, "<tag>" ) == 0 ||
          kasciistricmp( f, "Subject" ) == 0 ||
-         kasciistricmp( f, "list-id" ) == 0 ||
          kasciistricmp( f, "from" ) == 0 ||
          kasciistricmp( f, "<any header>" )== 0) {
         part = Envelope;
@@ -683,6 +682,7 @@ SearchRule::RequiredPart SearchRuleString::requiredPart() const
                kasciistricmp( f, "cc" ) == 0 ||
                kasciistricmp( f, "bcc" ) == 0 ||
                kasciistricmp( f, "resent-from" ) == 0 ||
+               kasciistricmp( f, "list-id" ) == 0 ||
                kasciistricmp( f, "x-loop" ) == 0 ||
                kasciistricmp( f, "x-mailing-list" ) == 0 ||
                kasciistricmp( f, "x-spam-flag" ) == 0 ||
