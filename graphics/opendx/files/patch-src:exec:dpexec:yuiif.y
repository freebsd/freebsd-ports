--- src/exec/dpexec/yuiif.y-orig	Mon Jul 31 10:10:38 2000
+++ src/exec/dpexec/yuiif.y	Tue Nov 26 14:31:53 2002
@@ -1550,18 +1550,21 @@
 		    if (! _dxd_exUIPacket)
 			yyerrok;
 		}
+		;
 
 rightparen	: T_RPAR
 		{
 		    if (! _dxd_exUIPacket)
 			yyerrok;
 		}
+		;
 
 rightbracket	: T_RBRA
 		{
 		    if (! _dxd_exUIPacket)
 			yyerrok;
 		}
+		;
 
 id		: T_ID
 		{
