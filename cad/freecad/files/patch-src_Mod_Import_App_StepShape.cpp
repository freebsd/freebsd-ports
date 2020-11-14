--- src/Mod/Import/App/StepShape.cpp.orig	2020-11-14 20:26:44 UTC
+++ src/Mod/Import/App/StepShape.cpp
@@ -34,6 +34,7 @@
 # include <Interface_Static.hxx>
 # include <Message_Messenger.hxx>
 # include <Message_PrinterOStream.hxx>
+# include <Standard_Version.hxx>
 
 # include <Base/FileInfo.h>
 # include <Base/Exception.h>
@@ -85,18 +86,26 @@ int StepShape::read(const char* fileName)
     Handle(StepData_StepModel) model = aReader.StepModel();
     //rank = model->NextNumberForLabe(label, 0, Standard_False);
 
+#if OCC_VERSION_HEX < 0x070401
     Handle(Message_PrinterOStream) mstr = new Message_PrinterOStream();
     Handle(Message_Messenger) msg = new Message_Messenger(mstr);
 
     std::cout << "dump of step header:" << std::endl;
 
     model->DumpHeader(msg);
+#else
+    model->DumpHeader(std::cout);
+#endif
 
     for(int nent=1;nent<=model->NbEntities();nent++) {
       Handle(Standard_Transient) entity=model->Entity(nent);
       
       std::cout << "label entity " << nent << ":" ;
+#if OCC_VERSION_HEX < 0x070401
       model->PrintLabel(entity,msg);
+#else
+      model->PrintLabel(entity,std::cout);
+#endif
       std::cout << ";"<< entity->DynamicType()->Name() << std::endl;
     }
 
