--- src/Mod/Import/Gui/AppImportGuiPy.cpp.orig	2020-11-14 19:49:55 UTC
+++ src/Mod/Import/Gui/AppImportGuiPy.cpp
@@ -391,12 +391,16 @@ class Module : public Py::ExtensionModule<Module> (pri
                         throw Py::Exception(PyExc_IOError, "cannot read STEP file");
                     }
 
+#if OCC_VERSION_HEX < 0x070500
                     Handle(Message_ProgressIndicator) pi = new Part::ProgressIndicator(100);
                     aReader.Reader().WS()->MapReader()->SetProgress(pi);
                     pi->NewScope(100, "Reading STEP file...");
                     pi->Show();
+#endif
                     aReader.Transfer(hDoc);
+#if OCC_VERSION_HEX < 0x070500
                     pi->EndScope();
+#endif
                 }
                 catch (OSD_Exception& e) {
                     Base::Console().Error("%s\n", e.GetMessageString());
@@ -423,12 +427,16 @@ class Module : public Py::ExtensionModule<Module> (pri
                         throw Py::Exception(Base::BaseExceptionFreeCADError, "cannot read IGES file");
                     }
 
+#if OCC_VERSION_HEX < 0x070500
                     Handle(Message_ProgressIndicator) pi = new Part::ProgressIndicator(100);
                     aReader.WS()->MapReader()->SetProgress(pi);
                     pi->NewScope(100, "Reading IGES file...");
                     pi->Show();
+#endif
                     aReader.Transfer(hDoc);
+#if OCC_VERSION_HEX < 0x070500
                     pi->EndScope();
+#endif
                     // http://opencascade.blogspot.de/2009/03/unnoticeable-memory-leaks-part-2.html
                     Handle(IGESToBRep_Actor)::DownCast(aReader.WS()->TransferReader()->Actor())
                             ->SetModel(new IGESData_IGESModel);
@@ -601,12 +609,16 @@ class Module : public Py::ExtensionModule<Module> (pri
                     throw Py::Exception(PyExc_IOError, "cannot read STEP file");
                 }
 
+#if OCC_VERSION_HEX < 0x070500
                 Handle(Message_ProgressIndicator) pi = new Part::ProgressIndicator(100);
                 aReader.Reader().WS()->MapReader()->SetProgress(pi);
                 pi->NewScope(100, "Reading STEP file...");
                 pi->Show();
+#endif
                 aReader.Transfer(hDoc);
+#if OCC_VERSION_HEX < 0x070500
                 pi->EndScope();
+#endif
             }
             else if (file.hasExtension("igs") || file.hasExtension("iges")) {
                 Base::Reference<ParameterGrp> hGrp = App::GetApplication().GetUserParameter()
@@ -623,12 +635,16 @@ class Module : public Py::ExtensionModule<Module> (pri
                     throw Py::Exception(PyExc_IOError, "cannot read IGES file");
                 }
 
+#if OCC_VERSION_HEX < 0x070500
                 Handle(Message_ProgressIndicator) pi = new Part::ProgressIndicator(100);
                 aReader.WS()->MapReader()->SetProgress(pi);
                 pi->NewScope(100, "Reading IGES file...");
                 pi->Show();
+#endif
                 aReader.Transfer(hDoc);
+#if OCC_VERSION_HEX < 0x070500
                 pi->EndScope();
+#endif
                 // http://opencascade.blogspot.de/2009/03/unnoticeable-memory-leaks-part-2.html
                 Handle(IGESToBRep_Actor)::DownCast(aReader.WS()->TransferReader()->Actor())
                         ->SetModel(new IGESData_IGESModel);
