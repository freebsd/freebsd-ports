--- src/gen_crq.cpp.orig	2015-10-21 17:26:38 UTC
+++ src/gen_crq.cpp
@@ -99,9 +99,9 @@ main(int argc, char *argv[]) {
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
@@ -124,13 +124,13 @@ main(int argc, char *argv[]) {
 					*cp = '_';
 			}
 			string filename = string(argv[optind]) + ".tq5";
-			cout << "Creating CRQ for " << crq.callSign << " DXCC=" << crq.dxccEntity << endl;
+			std::cout << "Creating CRQ for " << crq.callSign << " DXCC=" << crq.dxccEntity << endl;
 			if (tqsl_createCertRequest(filename.c_str(), &crq, 0, 0))
 				throw tqslexc();
 		}
 		return EXIT_SUCCESS;
 	} catch(exception& x) {
-		cerr << "Aborting: " << x.what() << endl;
+		std::cerr << "Aborting: " << x.what() << endl;
 		return EXIT_FAILURE;
 	}
 	return EXIT_SUCCESS;
