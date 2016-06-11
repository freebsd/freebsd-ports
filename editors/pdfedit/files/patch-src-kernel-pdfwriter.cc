--- src/kernel/pdfwriter.cc.orig	2010-04-26 11:39:32 UTC
+++ src/kernel/pdfwriter.cc
@@ -110,7 +110,7 @@ using namespace observer;
 		printf("Unsupported context.\n");
 		return;
 	}
-	shared_ptr<const IPdfWriter::ChangeContext> progressContext=
+	boost::shared_ptr<const IPdfWriter::ChangeContext> progressContext=
 		dynamic_pointer_cast<const IPdfWriter::ChangeContext>(context);
 	size_t total=progressContext->getScope()->total;
 	if(!started)
@@ -427,7 +427,7 @@ using namespace std;
 	// contain binary data
 	if(obj.isStream())
 	{
-		shared_ptr<FilterStreamWriter> filter = FilterStreamWriter::getInstance(obj);
+		boost::shared_ptr<FilterStreamWriter> filter = FilterStreamWriter::getInstance(obj);
 		assert(filter->supportObject(obj));
 		filter->compress(obj, ref, stream);
 	}else
@@ -502,11 +502,11 @@ using namespace boost;
 	size_t index=0;
 	
 	// creates context for observers
-	shared_ptr<OperationScope> scope(new OperationScope());
+	boost::shared_ptr<OperationScope> scope(new OperationScope());
 	scope->total=objectList.size();
 	scope->task=CONTENT;
-	shared_ptr<ChangeContext> context(new ChangeContext(scope));
-	shared_ptr<OperationStep> newValue(new OperationStep());
+	boost::shared_ptr<ChangeContext> context(new ChangeContext(scope));
+	boost::shared_ptr<OperationStep> newValue(new OperationStep());
 
 	// prepares offTable and writes objects
 	for(i=objectList.begin(); i!=objectList.end(); i++, index++)
@@ -659,10 +659,10 @@ size_t OldStylePdfWriter::writeTrailer(c
 	utilsPrintDbg(DBG_DBG, "Writing "<<subSectionTable.size()<<" subsections");
 	
 	// creates context for observers
-	shared_ptr<OperationScope> scope(new OperationScope());
+	boost::shared_ptr<OperationScope> scope(new OperationScope());
 	scope->total=subSectionTable.size();
 	scope->task=TRAILER;
-	shared_ptr<ChangeContext> context(new ChangeContext(scope));
+	boost::shared_ptr<ChangeContext> context(new ChangeContext(scope));
 
 	// writes all subsection
 	size_t index=1;
@@ -704,7 +704,7 @@ size_t OldStylePdfWriter::writeTrailer(c
 		}
 		
 		// notifies observers
-		shared_ptr<OperationStep> newValue(new OperationStep());
+		boost::shared_ptr<OperationStep> newValue(new OperationStep());
 		newValue->currStep=index;
 		notifyObservers(newValue, context);
 	}
