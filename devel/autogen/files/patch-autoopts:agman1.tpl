--- autoopts/agman1.tpl.orig	Mon Jul 15 19:39:33 2002
+++ autoopts/agman1.tpl	Mon Jul 15 19:48:10 2002
@@ -432,9 +432,9 @@
      ENDIF :+][+:
   ESAC     :+][+:
 ENDIF      :+]
-_End_Of_Man_[+:
+_End_Of_Man_{+
 
-(shell (out-pop #t) ) :+]
+(shell (out-pop #t) ) +}
 .PP
 This manual page was \fIAutoGen\fP-erated from the \fB[+:prog_name:+]\fP
 option definitions.[+: #
