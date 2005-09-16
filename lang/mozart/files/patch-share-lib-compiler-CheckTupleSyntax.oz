--- ./share/lib/compiler/CheckTupleSyntax.oz.orig	Tue Oct 10 19:24:15 2000
+++ ./share/lib/compiler/CheckTupleSyntax.oz	Sat Sep  3 18:46:09 2005
@@ -6,8 +6,8 @@
 %%%   Leif Kornstaedt, 1998
 %%%
 %%% Last change:
-%%%   $Date: 2000/10/10 23:24:15 $ by $Author: duchier $
-%%%   $Revision: 1.21 $
+%%%   $Date: 2005/02/03 11:50:19 $ by $Author: glynn $
+%%%   $Revision: 1.21.16.1 $
 %%%
 %%% This file is part of Mozart, an implementation of Oz 3:
 %%%    http://www.mozart-oz.org
@@ -115,6 +115,8 @@
 	 {Type.ask.int I} {Coord C}
       [] fLoop(E C) then {Phrase E} {Coord C}
       [] fMacro(Es C) then {ForAll Es Phrase} {Coord C}
+      [] fDotAssign(P1 P2 C) then {Phrase P1} {Phrase P2} {Coord C}
+      [] fColonEquals(P1 P2 C) then {Phrase P1} {Phrase P2} {Coord C}
       [] fFOR(Ds B C) then {ForAll Ds ForDecl} {Phrase B} {Coord C}
       else {FDExpression X}
       end
