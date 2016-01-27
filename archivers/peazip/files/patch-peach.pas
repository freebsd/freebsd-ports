--- peach.pas	2016-01-27 13:08:24.382120000 -0500
+++ peach.pas	2016-01-27 13:17:34.207034000 -0500
@@ -4445,6 +4445,7 @@
   APPLICATION5  = '';
   APPLICATION6  = '';
   APPLICATION7  = '';
+  APPLICATION8  = '';
   {$ENDIF}
   {$IFDEF NETBSD}
   EXEEXT        = '';
@@ -4455,6 +4456,7 @@
   APPLICATION5  = '';
   APPLICATION6  = '';
   APPLICATION7  = '';
+  APPLICATION8  = '';
   {$ENDIF}
   {$IFDEF DARWIN}
   EXEEXT        = '';
@@ -4465,6 +4467,7 @@
   APPLICATION5  = '';
   APPLICATION6  = '';
   APPLICATION7  = '';
+  APPLICATION8  = '';
   {$ENDIF}
 
 var
@@ -6526,7 +6529,7 @@
 
 procedure setdescription_advcustedit;
 var
-   s:utf8string;
+   s:AnsiString;
    sg:TStringGrid;
 begin
 sg:=Form_peach.StringGridCustedit1;
@@ -6541,7 +6544,7 @@
 
 procedure setdescription_custedit;
 var
-   s:utf8string;
+   s:AnsiString;
 begin
 s:=Form_peach.StringGridCustedit.Cells[1,Form_peach.StringGridCustedit.Row];
 if InputQuery(txt_description, '', s) then
@@ -6553,7 +6556,7 @@
 
 procedure editstring1_advcustedit;
 var
-   s:utf8string;
+   s:AnsiString;
 begin
 s:=Form_peach.StringGridCustedit1.Cells[2,Form_peach.StringGridCustedit1.Row];
 if InputQuery(txt_2_5_strbefore, '', s) then
@@ -6566,7 +6569,7 @@
 
 procedure editstring2_advcustedit;
 var
-   s:utf8string;
+   s:AnsiString;
 begin
 s:=Form_peach.StringGridCustedit1.Cells[3,Form_peach.StringGridCustedit1.Row];
 if InputQuery(txt_2_5_strafter, '', s) then
@@ -6579,7 +6582,7 @@
 
 procedure editstring3_advcustedit;
 var
-   s:utf8string;
+   s:AnsiString;
 begin
 s:=Form_peach.StringGridCustedit1.Cells[4,Form_peach.StringGridCustedit1.Row];
 if InputQuery(txt_3_3_stralt, '', s) then
@@ -6592,7 +6595,7 @@
 
 procedure editapp_custedit;
 var
-   s:utf8string;
+   s:AnsiString;
 begin
 s:=Form_peach.StringGridCustedit.Cells[2,Form_peach.StringGridCustedit.Row];
 if InputQuery(txt_edit, '', s) then
