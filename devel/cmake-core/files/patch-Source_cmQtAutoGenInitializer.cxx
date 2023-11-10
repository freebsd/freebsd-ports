CMake >= 3.27 exports the CXX std to moc. This is a workaround for
a moc parsing bug that happens parsing headers from libc++ < 14 when
the CXX std > 17.

usr/include/c++/v1/concept:318:1: error: Parse error at "::" [1]

Moc should theoretically be able to parse this. [2] Not exactly sure
why it's failing.

[1] https://cgit.freebsd.org/src/tree/contrib/llvm-project/libcxx/include/concepts?h=stable/12#n318
[2] https://code.qt.io/cgit/qt/qtbase.git/tree/src/tools/moc/moc.cpp?h=6.6.0#n631

--- Source/cmQtAutoGenInitializer.cxx.orig	2023-10-06 13:08:35 UTC
+++ Source/cmQtAutoGenInitializer.cxx
@@ -1797,6 +1797,10 @@ bool cmQtAutoGenInitializer::SetupWriteAutogenInfo()
       if (this->Moc.PredefsCmd.size() >= 3) {
         this->Moc.PredefsCmd.insert(this->Moc.PredefsCmd.begin() + 1,
                                     CompileOptionValue);
+#if defined(__FreeBSD__) && __FreeBSD_version < 1302000
+        this->Moc.PredefsCmd.insert(this->Moc.PredefsCmd.begin() + 1,
+                                    "-D_LIBCPP_HAS_NO_CONCEPTS");
+#endif
       }
     }
     info.SetArray("MOC_PREDEFS_CMD", this->Moc.PredefsCmd);
