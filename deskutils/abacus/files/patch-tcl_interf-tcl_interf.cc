--- tcl_interf/tcl_interf.cc.orig	Mon Oct 26 00:38:39 1998
+++ tcl_interf/tcl_interf.cc	Mon Aug 11 21:05:45 2003
@@ -2471,8 +2471,8 @@
 		  sheet->add_graph_deps(grp);
 		  
 		  sprintf(command,
-			  "[canvasFromSheet $activeSheet] delete graph_%d
-                          doDrawGraph [GetGraphParams $activeSheet %d] %d ",
+			  "[canvasFromSheet $activeSheet] delete graph_%d\n"
+                          "doDrawGraph [GetGraphParams $activeSheet %d] %d ",
 			  grp->number,grp->number,grp->number);
                     
 		  sheet->RunScript(command);
@@ -2487,8 +2487,8 @@
 		  sheet->add_graph_deps(grp);
 		  
 		  sprintf(command,
-			  "[canvasFromSheet $activeSheet] delete graph_%d
-                          doDrawGraph [GetGraphParams $activeSheet %d] %d ",
+			  "[canvasFromSheet $activeSheet] delete graph_%d\n"
+                          "doDrawGraph [GetGraphParams $activeSheet %d] %d ",
 			  grp->number,grp->number,grp->number);
 			
 		  sheet->RunScript(command);
@@ -2528,8 +2528,8 @@
 		  sheet->add_graph_deps(grp);
 		  
 		  sprintf(command,
-			  "[canvasFromSheet $activeSheet] delete graph_%d
-                          doDrawGraph [GetGraphParams $activeSheet %d] %d ",
+			  "[canvasFromSheet $activeSheet] delete graph_%d\n"
+                          "doDrawGraph [GetGraphParams $activeSheet %d] %d ",
 			  grp->number,grp->number,grp->number);
                     
 		  sheet->RunScript(command);
@@ -2544,8 +2544,8 @@
 		  sheet->add_graph_deps(grp);
 		  
 		  sprintf(command,
-			  "[canvasFromSheet $activeSheet] delete graph_%d
-                          doDrawGraph [GetGraphParams $activeSheet %d] %d ",
+			  "[canvasFromSheet $activeSheet] delete graph_%d\n"
+                          "doDrawGraph [GetGraphParams $activeSheet %d] %d ",
 			  grp->number,grp->number,grp->number);
 			
 		  sheet->RunScript(command);
@@ -2719,8 +2719,8 @@
 				      grp->number);
 			    else
 			      sprintf(command,
-				      "[canvasFromSheet $activeSheet] delete graph_%d
-                                      doDrawGraph [GetGraphParams $activeSheet %d] %d ",
+				      "[canvasFromSheet $activeSheet] delete graph_%d\n"
+                                      "doDrawGraph [GetGraphParams $activeSheet %d] %d ",
 				      grp->number,grp->number,grp->number);
 			
 			    sheet->RunScript(command);
@@ -2820,8 +2820,8 @@
 				  grp->number);
 			else
 			  sprintf(command,
-				  "[canvasFromSheet $activeSheet] delete graph_%d
-                                  doDrawGraph [GetGraphParams $activeSheet %d] %d ",
+				  "[canvasFromSheet $activeSheet] delete graph_%d\n"
+                                  "doDrawGraph [GetGraphParams $activeSheet %d] %d ",
 				  grp->number,grp->number,grp->number);
 			
 			sheet->RunScript(command);
@@ -2868,8 +2868,8 @@
 				      grp->number);
 			    else
 			      sprintf(command,
-				      "[canvasFromSheet $activeSheet] delete graph_%d
-                                      doDrawGraph [GetGraphParams $activeSheet %d] %d ",
+				      "[canvasFromSheet $activeSheet] delete graph_%d\n"
+                                      "doDrawGraph [GetGraphParams $activeSheet %d] %d ",
 				      grp->number,grp->number,grp->number);
 			   
 			    sheet->RunScript(command);
