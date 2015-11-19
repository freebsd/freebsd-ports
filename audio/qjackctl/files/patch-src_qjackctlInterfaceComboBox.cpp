--- src/qjackctlInterfaceComboBox.cpp.orig	2015-10-28 15:24:52 UTC
+++ src/qjackctlInterfaceComboBox.cpp
@@ -191,9 +191,16 @@ private:
 
 			// Fill HostApi info...
 			const PaHostApiIndex iNumHostApi = Pa_GetHostApiCount();
+#ifdef __clang__
+			QString *hostNames = new QString[iNumHostApi];
+#else
 			QString hostNames[iNumHostApi];
+#endif
 			for (PaHostApiIndex i = 0; i < iNumHostApi; ++i)
 				hostNames[i] = QString(Pa_GetHostApiInfo(i)->name);
+#ifdef __clang__
+			delete [] hostNames;
+#endif
 
 			// Fill device info...
 			const PaDeviceIndex iNumDevice = Pa_GetDeviceCount();
