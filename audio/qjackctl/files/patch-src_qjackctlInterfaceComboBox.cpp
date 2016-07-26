--- src/qjackctlInterfaceComboBox.cpp.orig	2016-04-05 15:57:30 UTC
+++ src/qjackctlInterfaceComboBox.cpp
@@ -210,9 +210,16 @@ private:
 
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
