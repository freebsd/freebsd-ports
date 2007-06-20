--- team-framework/parser/configurationparser.h.orig	Fri Jan  7 02:59:28 2005
+++ team-framework/parser/configurationparser.h	Thu Jun 14 13:28:41 2007
@@ -51,7 +51,7 @@
 	* Public stuff
 	*/
 	public:
-		ConfigurationParser::ConfigurationParser() throw (bad_exception);
+		ConfigurationParser() throw (bad_exception);
 		void addFile(const string& filename) throw(ParserException, bad_exception);
 		const map<string, map<string, string> >& getConfigurationData() const throw();
 	/*
