--- bforce/sess_call.c.orig	Thu Nov 21 23:22:56 2002
+++ bforce/sess_call.c	Sat May 29 22:37:30 2004
@@ -609,10 +609,20 @@
 		
 		if( !opts->hiddline )
 		{
-			if( timevec_isdefined(&state.override.worktime) )
-				goodtime = timevec_isnow(&state.override.worktime, now);
+			if( state.override.sFlags && !nodelist_checkflag(state.override.sFlags, "CM") )
+				goodtime = TRUE;
 			else
-				goodtime = timevec_isnow(&state.node.worktime, now);
+			{
+				if( timevec_isdefined(&state.override.worktime) )
+					goodtime = timevec_isnow(&state.override.worktime, now);
+				else
+				{
+					if( !nodelist_checkflag(state.node.flags, "CM") )
+						goodtime = TRUE;
+					else
+						goodtime = timevec_isnow(&state.node.worktime, now);
+				}
+			}
 		}
 		else
 			goodtime = timevec_isnow(&state.override.worktime, now);
