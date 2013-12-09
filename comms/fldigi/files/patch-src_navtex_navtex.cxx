--- src/navtex/navtex.cxx.orig	2013-11-17 19:46:34.808897323 -0500
+++ src/navtex/navtex.cxx	2013-11-17 19:56:56.135855100 -0500
@@ -177,12 +177,16 @@
 	if( ! std::getline( istrm, parsed_str, delim ) ) return false ;
 	std::stringstream sstrm( parsed_str );
 	sstrm >> ref ;
-	return sstrm ;
+	return true ;
 }
 
 static bool read_until_delim( std::istream & istrm, std::string & ref )
 {
-	return std::getline( istrm, ref, delim );
+	std::getline( istrm, ref, delim );
+	if ( (istrm.rdstate() & std::ifstream::goodbit) == 0 )
+		return true ;
+	else
+		return false ;
 }
 
 class NavtexRecord
@@ -1113,8 +1117,8 @@
 		static int cnt_read_data = 0 ;
 		/// This centers the carrier where the activity is the strongest.
 		static const int bw[][2] = {
-			{ -deviation_f - 2, -deviation_f + 8 },
-			{  deviation_f - 8,  deviation_f + 2 } };
+			{ - static_cast<int>(deviation_f) - 2, - static_cast<int>(deviation_f) + 8 },
+			{  static_cast<int>(deviation_f) - 8,  static_cast<int>(deviation_f) + 2 } };
        		double max_carrier = wf->powerDensityMaximum( 2, bw );
 
 		/// Do not change the frequency too quickly if an image is received.
