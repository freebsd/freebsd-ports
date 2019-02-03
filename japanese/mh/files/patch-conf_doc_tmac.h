--- conf/doc/tmac.h.orig	1993-12-01 04:00:20 UTC
+++ conf/doc/tmac.h
@@ -3,62 +3,46 @@
 .\"    Try to keep only one copy of the documentation around
 .\"    by re-defining macros and so forth.
 .\"
-.fc ^ ~
 .\"    I pity the fool who tampers with the next line...
 .ds ZZ -man
-.de SC					\" Title section
-.TH \\$1 \\$2 @(MHCENTERFOOT) @(MHLEFTFOOT)
-..
-.de NA					\" Name section
-.SH NAME
-..
-.de SY					\" Synopsis section
-.SH SYNOPSIS
-.in +.5i
-.ti -.5i
-..
-.de DE					\" Description section
-.in -.5i
-.SH DESCRIPTION
-..
-.de Fi					\" Files section
+.de Fi
 .SH FILES
 .nf
 .ta \w'@(MHETCPATH)/ExtraBigFileName  'u
 ..
-.de Pr					\" Profile section
-.SH "PROFILE\ COMPONENTS"
+.de Pr
+.SH "PROFILE COMPONENTS"
 .nf
 .ta 2.4i
 .ta \w'ExtraBigProfileName  'u
 ..
-.de Ps					\" Profile next
+.de Ps
 .br
 ..
-.de Sa					\" See Also section
+.de Sa
 .fi
-.SH "SEE\ ALSO"
+.SH "SEE ALSO"
 ..
-.de De					\" Defaults section
+.de De
 .SH "DEFAULTS"
 .nf
 ..
-.de Ds					\" Defaults next
+.de Ds
 .br
 ..
-.de Co					\" Context section
+.de Co
 .fi
 .SH CONTEXT
 ..
-.de Hh					\" Hints section
+.de Hh
 .fi
 .SH "HELPFUL HINTS"
 ..
-.de Hi					\" History section
+.de Hi
 .fi
 .SH HISTORY
 ..
-.de Bu					\" Bugs section
+.de Bu
 .fi
 .SH BUGS
 ..
@@ -75,3 +59,8 @@
 .de re
 .ta 0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i +0.5i
 ..
+.\" This defines appropriate quote strings for nroff and troff
+.ds lq \&"
+.ds rq \&"
+.if t .ds lq ``
+.if t .ds rq ''
