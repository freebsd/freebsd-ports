--- sope-mime/NGMime/NGMimePartGenerator.h.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMime/NGMimePartGenerator.h
@@ -149,7 +149,7 @@
   The delegate can select which NGMimeBodyGenerator should de used
   for generate the given part.
 */  
-- (id<NGMimePartGenerator>)multipartBodyGenerator:(id<NGMimeBodyGenerator>)
+- (id<NGMimePartGenerator>)multipartBodyGenerator:(id<NGMimeBodyGenerator>)aGenerator
   generatorForPart:(id<NGMimePart>)_part;
 
 - (BOOL)useMimeData;
