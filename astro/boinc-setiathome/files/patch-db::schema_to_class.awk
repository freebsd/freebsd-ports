--- ../db/schema_to_class.awk.orig	Thu Sep 30 21:58:31 2004
+++ ../db/schema_to_class.awk	Sun Oct  3 21:45:08 2004
@@ -344,15 +344,15 @@
 		  print "\tvoid parse_xml(const std::string &s,const char *tag=\""table"\");" >headerfile
 		  print "  private:\n};\n\n" >headerfile
 		  if (is_typedef) {
-		    print "const char * const db_type<"table">::type_name=\""table"\";" >sourcefile
-		    print "const char * db_type<"table">::_search_tag=type_name;" >sourcefile
-		    print "const int db_type<"table">::_nfields="nfields-1";" >sourcefile
-		    printf("const char * const db_type<%s>::column_names[%d]={",table,nfields-1) >sourcefile
+		    print "template <> const char * const db_type<"table">::type_name=\""table"\";" >sourcefile
+		    print "template <> const char * db_type<"table">::_search_tag=type_name;" >sourcefile
+		    print "template <> const int db_type<"table">::_nfields="nfields-1";" >sourcefile
+		    printf("template <> const char * const db_type<%s>::column_names[%d]={",table,nfields-1) >sourcefile
 		  } else { 
-		    print "const char * const db_table<"table">::table_name=\""table"\";" >sourcefile
-		    print "const char * db_table<"table">::_search_tag=table_name;" >sourcefile
-		    print "const int db_table<"table">::_nfields="nfields-1";" >sourcefile
-		    printf("const char * const db_table<%s>::column_names[%d]={",table,nfields-1) >sourcefile
+		    print "template <> const char * const db_table<"table">::table_name=\""table"\";" >sourcefile
+		    print "template <> const char * db_table<"table">::_search_tag=table_name;" >sourcefile
+		    print "template <> const int db_table<"table">::_nfields="nfields-1";" >sourcefile
+		    printf("template <> const char * const db_table<%s>::column_names[%d]={",table,nfields-1) >sourcefile
 		  }
 		  for (i=1;i<nfields;i++) printf("\"%s\"%s",fields[i],comma[i]) >sourcefile
 		  print "};\n" >sourcefile
@@ -618,7 +618,7 @@
 		      if (sis_deftype) print "\trv << xml_indent(-2);" > sourcefile
 		      print "\trv << \"</"fields[i]">\\n\"; " >sourcefile
 		    } else if (type[i]=="s") {
-		      print "\t{\n\t  std::string enc_field=xml_encode_string<char>("fields[i]",std::min(strlen("fields[i]"),sizeof("fields[i]")));" > sourcefile
+		      print "\t{\n\t  std::string enc_field=xml_encode_string("fields[i]",std::min(strlen("fields[i]"),sizeof("fields[i]")));" > sourcefile
 		      print "\t  rv << xml_indent() << \"<"fields[i]">\";" > sourcefile
 		      print "\t  rv << enc_field << \"</"fields[i]">\\n\";" >sourcefile
 		      print "\t}" >> sourcefile
