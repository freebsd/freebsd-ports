--- tcl_interf/event.cc.orig	Tue Oct 20 13:20:48 1998
+++ tcl_interf/event.cc	Mon Aug 11 21:12:28 2003
@@ -41,13 +41,13 @@
   sheet->recalc(aux);
   sheet->display(aux);
 
-  sprintf(command,"unhighlightActiveCell
-                   unhighlightCurrentRange [canvasFromSheet $activeSheet]
-                   unhighlightColSelection
-                   unhighlightRowSelection
-                   set activeCellCol %d
-                   set activeCellRow %d
-                   highlightActiveCell",col,row);
+  sprintf(command,"unhighlightActiveCell \n"
+                   "unhighlightCurrentRange [canvasFromSheet $activeSheet] \n"
+                   "unhighlightColSelection \n"
+                   "unhighlightRowSelection \n"
+                   "set activeCellCol %d \n"
+                   "set activeCellRow %d \n"
+                   "highlightActiveCell",col,row);
   sheet->RunScript(command);
 }
 
@@ -73,12 +73,12 @@
   char command[512];
   
   sprintf(command,
-	      "unhighlightActiveCell
-               unhighlightCurrentRange [canvasFromSheet $activeSheet]
-               unhighlightColSelection
-               unhighlightRowSelection
-               DeleteRowOrColumn $activeSheet %d %d %c 0
-	       highlightActiveCell",
+	      "unhighlightActiveCell\n"
+               "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+               "unhighlightColSelection\n"
+               "unhighlightRowSelection\n"
+               "DeleteRowOrColumn $activeSheet %d %d %c 0\n"
+	       "highlightActiveCell",
 	  cr_ind,cr_num,col_or_row);
   sheet->RunScript(command);
 
@@ -92,31 +92,31 @@
 
   if(col_or_row='c')
     sprintf(command,
-	    "unhighlightActiveCell
-             unhighlightCurrentRange [canvasFromSheet $activeSheet]
-             unhighlightColSelection
-             unhighlightRowSelection
-             InsertRowOrColumn $activeSheet %d %d c 0
-             redrawCanvas $activeSheet
-             set cols_selected [list %d %d]
-             highlightColSelection
-             set currentRange \
-                     [list %d 0 %d [expr [DefSheetHeight] - 1]]
-             highlightCurrentRange [canvasFromSheet $activeSheet]",
+	    "unhighlightActiveCell\n"
+             "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+             "unhighlightColSelection\n"
+             "unhighlightRowSelection\n"
+             "InsertRowOrColumn $activeSheet %d %d c 0\n"
+             "redrawCanvas $activeSheet\n"
+             "set cols_selected [list %d %d]\n"
+             "highlightColSelection\n"
+             "set currentRange \\\n"
+             "        [list %d 0 %d [expr [DefSheetHeight] - 1]]\n"
+             "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	    cr_ind,cr_num,cr_ind,cr_ind+cr_num-1,cr_ind,cr_ind+cr_num-1);
   else
     sprintf(command,
-	    "unhighlightActiveCell
-             unhighlightCurrentRange [canvasFromSheet $activeSheet]
-             unhighlightColSelection
-             unhighlightRowSelection
-             InsertRowOrColumn $activeSheet %d %d r 0
-             redrawCanvas $activeSheet
-             set rows_selected [list %d %d]
-             highlightRowSelection
-             set currentRange \
-                     [list 0 %d [expr [DefSheetWidth] - 1] %d]
-             highlightCurrentRange [canvasFromSheet $activeSheet]",
+	    "unhighlightActiveCell\n"
+             "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+             "unhighlightColSelection\n"
+             "unhighlightRowSelection\n"
+             "InsertRowOrColumn $activeSheet %d %d r 0\n"
+             "redrawCanvas $activeSheet\n"
+             "set rows_selected [list %d %d]\n"
+             "highlightRowSelection\n"
+             "set currentRange \\\n"
+             "        [list 0 %d [expr [DefSheetWidth] - 1] %d]\n"
+             "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	    cr_ind,cr_num,cr_ind,cr_ind+cr_num-1,cr_ind,cr_ind+cr_num-1);
   sheet->RunScript(command);
 
@@ -206,11 +206,11 @@
 
 
   sprintf(command,
-	      "unhighlightActiveCell
-               unhighlightCurrentRange [canvasFromSheet $activeSheet]
-               unhighlightColSelection
-               unhighlightRowSelection
-               InsertRowOrColumn $activeSheet %d %d %c 0",
+	      "unhighlightActiveCell\n"
+               "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+               "unhighlightColSelection\n"
+               "unhighlightRowSelection\n"
+               "InsertRowOrColumn $activeSheet %d %d %c 0",
 	  cr_ind,cr_num,col_or_row);
   sheet->RunScript(command);
   if(col_or_row=='c')
@@ -237,21 +237,21 @@
 
   if(col_or_row=='c')
     sprintf(command,
-	    "redrawCanvas $activeSheet
-             set cols_selected [list %d %d]
-             highlightColSelection
-             set currentRange \
-                 [list %d 0 %d [expr [DefSheetHeight] - 1]]
-             highlightCurrentRange [canvasFromSheet $activeSheet]",
+	    "redrawCanvas $activeSheet\n"
+             "set cols_selected [list %d %d]\n"
+             "highlightColSelection\n"
+             "set currentRange \\\n"
+             "    [list %d 0 %d [expr [DefSheetHeight] - 1]]\n"
+             "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	    cr_ind,cr_ind+cr_num-1,cr_ind,cr_ind+cr_num-1);
   else
     sprintf(command,
-	    "redrawCanvas $activeSheet
-             set rows_selected [list %d %d]
-             highlightRowSelection
-             set currentRange \
-                 [list 0 %d [expr [DefSheetWidth] - 1] %d]
-             highlightCurrentRange [canvasFromSheet $activeSheet]",
+	    "redrawCanvas $activeSheet\n"
+             "set rows_selected [list %d %d]\n"
+             "highlightRowSelection\n"
+             "set currentRange \\\n"
+             "    [list 0 %d [expr [DefSheetWidth] - 1] %d]\n"
+             "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	    cr_ind,cr_ind+cr_num-1,cr_ind,cr_ind+cr_num-1);
 
   sheet->RunScript(command);
@@ -263,12 +263,12 @@
   char command[512];
 
   sprintf(command,
-	      "unhighlightActiveCell
-               unhighlightCurrentRange [canvasFromSheet $activeSheet]
-               unhighlightColSelection
-               unhighlightRowSelection
-               DeleteRowOrColumn $activeSheet %d %d %c 0
-               highlightActiveCell",
+	      "unhighlightActiveCell\n"
+               "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+               "unhighlightColSelection\n"
+               "unhighlightRowSelection\n"
+               "DeleteRowOrColumn $activeSheet %d %d %c 0\n"
+               "highlightActiveCell",
 	  cr_ind,cr_num,col_or_row);
   sheet->RunScript(command);
   RedoGraph();
@@ -385,13 +385,13 @@
       sheet->recalc(aux);
       
       sprintf(command,
-	      "unhighlightActiveCell
-               unhighlightCurrentRange [canvasFromSheet $activeSheet]
-               unhighlightColSelection
-               unhighlightRowSelection
-               set activeCellCol %d
-               set activeCellRow %d
-               highlightActiveCell",x_start,y_start);
+	      "unhighlightActiveCell\n"
+               "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+               "unhighlightColSelection\n"
+               "unhighlightRowSelection\n"
+               "set activeCellCol %d\n"
+               "set activeCellRow %d\n"
+               "highlightActiveCell",x_start,y_start);
     }
   else
     {
@@ -426,12 +426,12 @@
 	delete new_savs[i];
       
       sprintf(command,
- 	      "unhighlightActiveCell
-               unhighlightCurrentRange [canvasFromSheet $activeSheet]
-               unhighlightColSelection
-               unhighlightRowSelection
-               set currentRange [list %d %d %d %d]
-               highlightCurrentRange [canvasFromSheet $activeSheet]",
+ 	      "unhighlightActiveCell\n"
+               "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+               "unhighlightColSelection\n"
+               "unhighlightRowSelection\n"
+               "set currentRange [list %d %d %d %d]\n"
+               "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	      x_start,y_start,x_end,y_end);
     }
   sheet->RunScript(command);
@@ -487,12 +487,12 @@
   to->UndoEvent();
   
   sprintf(command,
-	  "unhighlightActiveCell
-           unhighlightCurrentRange [canvasFromSheet $activeSheet]
-           unhighlightColSelection
-           unhighlightRowSelection
-           set currentRange [list %d %d %d %d]
-           highlightCurrentRange [canvasFromSheet $activeSheet]",
+	  "unhighlightActiveCell\n"
+           "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+           "unhighlightColSelection\n"
+           "unhighlightRowSelection\n"
+           "set currentRange [list %d %d %d %d]\n"
+           "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	  from->GetXStart(),from->GetYStart(),
 	  from->GetXEnd(),from->GetYEnd());
   (to->GetSheet())->RunScript(command);
@@ -506,12 +506,12 @@
   to->UndoEvent();
   
   sprintf(command,
-	  "unhighlightActiveCell
-           unhighlightCurrentRange [canvasFromSheet $activeSheet]
-           unhighlightColSelection
-           unhighlightRowSelection
-           set currentRange [list %d %d %d %d]
-           highlightCurrentRange [canvasFromSheet $activeSheet]",
+	  "unhighlightActiveCell\n"
+           "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+           "unhighlightColSelection\n"
+           "unhighlightRowSelection\n"
+           "set currentRange [list %d %d %d %d]\n"
+           "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	  to->GetXStart(),to->GetYStart(),
 	  to->GetXEnd(),to->GetYEnd());
   (to->GetSheet())->RunScript(command);
@@ -636,15 +636,15 @@
 	      sheet->display(aux);
 	      num++;
 	    }
-      sprintf(command,"unhighlightActiveCell
-                       unhighlightCurrentRange [canvasFromSheet $activeSheet]
-                       unhighlightColSelection
-                       unhighlightRowSelection
-                       set cols_selected [list %d %d]
-                       highlightColSelection
-                       set currentRange \
-		          [list %d 0 %d [expr [DefSheetHeight] - 1]]
-                       highlightCurrentRange [canvasFromSheet $activeSheet]",
+      sprintf(command,"unhighlightActiveCell\n"
+                       "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+                       "unhighlightColSelection\n"
+                       "unhighlightRowSelection\n"
+                       "set cols_selected [list %d %d]\n"
+                       "highlightColSelection\n"
+                       "set currentRange \\\n"
+		       "   [list %d 0 %d [expr [DefSheetHeight] - 1]]\n"
+                       "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	      startcol,endcol,startcol,endcol);
     }
   else if(startcol==-1)
@@ -660,15 +660,15 @@
 	      sheet->display(aux);
 	      num++;
 	    }
-      sprintf(command,"unhighlightActiveCell
-                       unhighlightCurrentRange [canvasFromSheet $activeSheet]
-                       unhighlightColSelection
-                       unhighlightRowSelection
-                       set rows_selected [list %d %d]
-                       highlightRowSelection
-                       set currentRange \
-		          [list 0 %d [expr [DefSheetWidth] - 1] %d]
-                       highlightCurrentRange [canvasFromSheet $activeSheet]",
+      sprintf(command,"unhighlightActiveCell\n"
+                       "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+                       "unhighlightColSelection\n"
+                       "unhighlightRowSelection\n"
+                       "set rows_selected [list %d %d]\n"
+                       "highlightRowSelection\n"
+                       "set currentRange \\n"
+		       "   [list 0 %d [expr [DefSheetWidth] - 1] %d]\n"
+                       "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	      startrow,endrow,startrow,endrow);
     }
   else if((endrow==-1)&&(endcol==-1)) // cell - && is not necessary
@@ -680,13 +680,13 @@
 	  lastformat=swp;
 	  sheet->display(aux);
 	  sprintf(command,
-		  "unhighlightActiveCell
-                   unhighlightCurrentRange [canvasFromSheet $activeSheet]
-                   unhighlightColSelection
-                   unhighlightRowSelection
-                   set activeCellCol %d
-                   set activeCellRow %d
-                   highlightActiveCell",startcol,startrow);
+		  "unhighlightActiveCell\n"
+                   "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+                   "unhighlightColSelection\n"
+                   "unhighlightRowSelection\n"
+                   "set activeCellCol %d\n"
+                   "set activeCellRow %d\n"
+                   "highlightActiveCell",startcol,startrow);
 	}
     }
   else
@@ -704,12 +704,12 @@
 	    }
 	  else
 	    internal_error();
-      sprintf(command,"unhighlightActiveCell
-                       unhighlightCurrentRange [canvasFromSheet $activeSheet]
-                       unhighlightColSelection
-                       unhighlightRowSelection
-                       set currentRange [list %d %d %d %d]
-                       highlightCurrentRange [canvasFromSheet $activeSheet]",
+      sprintf(command,"unhighlightActiveCell\n"
+                       "unhighlightCurrentRange [canvasFromSheet $activeSheet]\n"
+                       "unhighlightColSelection\n"
+                       "unhighlightRowSelection\n"
+                       "set currentRange [list %d %d %d %d]\n"
+                       "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	      startcol,startrow,endcol,endrow);
     }
   sheet->RunScript(command);
@@ -747,8 +747,8 @@
   }
   width=prev_width;
 
-  sprintf(command,"[canvasFromSheet $activeSheet] yview scroll 1 units
-                   [canvasFromSheet $activeSheet] yview scroll -1 units");
+  sprintf(command,"[canvasFromSheet $activeSheet] yview scroll 1 units\n"
+                   "[canvasFromSheet $activeSheet] yview scroll -1 units");
   sheet->RunScript(command);
 }
 
@@ -774,8 +774,8 @@
   sheet->set_row_height(row,height);
   height=prev_height;
   
-  sprintf(command,"[canvasFromSheet $activeSheet] yview scroll 1 units
-                   [canvasFromSheet $activeSheet] yview scroll -1 units");
+  sprintf(command,"[canvasFromSheet $activeSheet] yview scroll 1 units\n"
+                   "[canvasFromSheet $activeSheet] yview scroll -1 units");
   sheet->RunScript(command);
 }
 
@@ -797,13 +797,13 @@
 {
   char command[512];
 
-  sprintf(command,"doDeleteGraph %d
-                   unhighlightActiveCell
-                   unhighlightCurrentRange [canvasFromSheet $activeSheet] 
-                   unhighlightColSelection
-                   unhighlightRowSelection
-                   set currentRange [list %d %d %d %d]
-                   highlightCurrentRange [canvasFromSheet $activeSheet]",
+  sprintf(command,"doDeleteGraph %d\n"
+                   "unhighlightActiveCell\n"
+                   "unhighlightCurrentRange [canvasFromSheet $activeSheet] \n"
+                   "unhighlightColSelection\n"
+                   "unhighlightRowSelection\n"
+                   "set currentRange [list %d %d %d %d]\n"
+                   "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	           gr->number,
                    gr->range.start.col,gr->range.start.row,
                    gr->range.end.col,gr->range.end.row);
@@ -884,13 +884,13 @@
 {
   char command[512];
   
-  sprintf(command,"doDeleteGraph %d
-                   unhighlightActiveCell
-                   unhighlightCurrentRange [canvasFromSheet $activeSheet] 
-                   unhighlightColSelection
-                   unhighlightRowSelection
-                   set currentRange [list %d %d %d %d]
-                   highlightCurrentRange [canvasFromSheet $activeSheet]",
+  sprintf(command,"doDeleteGraph %d\n"
+                   "unhighlightActiveCell\n"
+                   "unhighlightCurrentRange [canvasFromSheet $activeSheet] \n"
+                   "unhighlightColSelection\n"
+                   "unhighlightRowSelection\n"
+                   "set currentRange [list %d %d %d %d]\n"
+                   "highlightCurrentRange [canvasFromSheet $activeSheet]",
 	           gr->number,
                    gr->range.start.col,gr->range.start.row,
                    gr->range.end.col,gr->range.end.row);
@@ -931,9 +931,9 @@
 
   sheet->add_graph_deps(sheet->graphs[i]);
 
-  sprintf(command," [canvasFromSheet $activeSheet] delete graphrect
-                    [canvasFromSheet $activeSheet] delete graph_%d
-                    doDrawGraph [GetGraphParams $activeSheet %d] %d ",
+  sprintf(command," [canvasFromSheet $activeSheet] delete graphrect\n"
+                    "[canvasFromSheet $activeSheet] delete graph_%d\n"
+                    "doDrawGraph [GetGraphParams $activeSheet %d] %d ",
 	            grph->number,grph->number,grph->number);
 
   delete grph;
