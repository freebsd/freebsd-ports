diff -ruN bforce-0.22.8.kst7/source/bforce/prot_emsi.c bforce-0.22.8.kst8/source/bforce/prot_emsi.c
--- bforce/prot_emsi.c	Thu Nov 21 23:22:56 2002
+++ bforce/prot_emsi.c	Sat Nov 30 01:41:15 2002
@@ -829,10 +829,14 @@
 	/* ----------------------------------------------------------------- */
 	if( state.caller == 0 && hrc != HRC_BAD_PASSWD )
 	{
-		emsi->have_traf = emsi->have_moh = 1;
+		emsi->have_traf = 1;
 		emsi->netmail_size = state.traff_send.netmail_size;
 		emsi->arcmail_size = state.traff_send.arcmail_size;
-		emsi->files_size = state.traff_send.files_size;
+		if ( state.traff_send.files_size )
+		{
+			emsi->have_moh = 1;
+			emsi->files_size = state.traff_send.files_size;
+		}	
 	}
 }
 
