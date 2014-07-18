--- src/gen_crq.cpp.orig	2014-07-17 03:33:28.000000000 -0700
+++ src/gen_crq.cpp	2014-07-17 03:34:02.000000000 -0700
@@ -99,9 +99,9 @@
 				throw tqslexc();
 			if (tqsl_getCertificateDXCCEntity(sign_cert, &cdxcc))
 				throw tqslexc();
-			cout << "Signing certificate issuer: " << buf << endl;
-			cout << "Signing certificate serial: " << serial << endl;
-			cout << "  Signing certificate DXCC: " << cdxcc << endl;
+			std::cout << "Signing certificate issuer: " << buf << endl;
+			std::cout << "Signing certificate serial: " << serial << endl;
+			std::cout << "  Signing certificate DXCC: " << cdxcc << endl;
 			if (tqsl_beginSigning(sign_cert, const_cast<char *>(""), 0, 0))
 				throw tqslexc();
 		}
@@ -124,7 +124,7 @@
 					*cp = '_';
 			}
 			string filename = string(argv[optind]) + ".tq5";
-			cout << "Creating CRQ for " << crq.callSign << " DXCC=" << crq.dxccEntity << endl;
+			std::cout << "Creating CRQ for " << crq.callSign << " DXCC=" << crq.dxccEntity << endl;
 			if (tqsl_createCertRequest(filename.c_str(), &crq, 0, 0))
 				throw tqslexc();
 		}
