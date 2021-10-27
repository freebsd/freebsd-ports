--- src/pdfReader.vala.orig	2019-08-10 18:20:51 UTC
+++ src/pdfReader.vala
@@ -26,6 +26,7 @@ public class BookwormApp.pdfReader {
       debug("Initiated process for parsing of PDF Book located at:"+aBook.getBookLocation());
       //Extract the content of the PDF
       string extractionLocation = extractEBook(aBook.getBookLocation());
+      
       if("false" == extractionLocation){ //handle error condition
         aBook.setIsBookParsed(false);
         aBook.setParsingIssue(BookwormApp.Constants.TEXT_FOR_EXTRACTION_ISSUE);
@@ -60,30 +61,38 @@ public class BookwormApp.pdfReader {
   public static string extractEBook(string eBookLocation){
         info("[START] [FUNCTION:extractEBook] eBookLocation="+eBookLocation);
         string extractionLocation = "false";
-         debug("Initiated process for content extraction of PDF Book located at:"+eBookLocation);
+        
+        debug("Initiated process for content extraction of PDF Book located at:"+eBookLocation);
+         
         if(BookwormApp.Bookworm.settings == null){
             BookwormApp.Bookworm.settings = BookwormApp.Settings.get_instance();
         }
+        
         //create a location for extraction of eBook based on local storage prefference
         if(BookwormApp.Bookworm.settings.is_local_storage_enabled){
             extractionLocation = BookwormApp.Bookworm.bookworm_config_path + "/books/" + File.new_for_path(eBookLocation).get_basename();
         }else{
             extractionLocation = BookwormApp.Constants.EBOOK_EXTRACTION_LOCATION + File.new_for_path(eBookLocation).get_basename();
         }
+        
         //check and create directory for extracting contents of ebook
         BookwormApp.Utils.fileOperations("CREATEDIR", extractionLocation, "", "");
-        //extract eBook contents into temp location
-        BookwormApp.Utils.execute_async_multiarg_command_pipes({"pdftohtml",
-                                                              "-noframes",
-                                                              "-zoom", "2.0",
-                                                              "-wbt", "20.0",
-                                                              "-nomerge",
-                                                              eBookLocation,
-                                                              extractionLocation + "/" + File.new_for_path(eBookLocation).get_basename()+".html"
-                                                            });
-
-        debug("Output of pdftohtml command:"+BookwormApp.Utils.spawn_async_with_pipes_output.str);
-        info("[END] [FUNCTION:extractEBook] extractionLocation="+extractionLocation);
+        
+        BookwormApp.Utils.execute_async_command({
+        	"pdftohtml",
+        	"-noframes",
+        	"-zoom", "2.0",
+        	"-wbt", "20.0",
+        	"-nomerge",
+        	eBookLocation,
+        	extractionLocation
+        	+ "/"
+        	+ File.new_for_path(eBookLocation).get_basename()
+        	+ ".html"
+    	});
+        
+        info("[END] [FUNCTION:extractEBook] extractionLocation=" + extractionLocation);
+        
         return extractionLocation;
   }
 
