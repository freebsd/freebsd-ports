Fix build with clang7:

	WeeklyTimesheet.cpp:287:37: error: default initialization of an object of const type 'const Lotsofcake::Configuration' requires a user-provided default constructor
	const Lotsofcake::Configuration configuration;

--- Charm/Lotsofcake/Configuration.cpp.orig	2018-09-03 18:53:25 UTC
+++ Charm/Lotsofcake/Configuration.cpp
@@ -43,6 +43,10 @@ static void setValueIfNotNull(QSettings 
     }
 }
 
+Lotsofcake::Configuration::Configuration()
+{
+}
+
 bool Lotsofcake::Configuration::isConfigured() const
 {
     return !username().isEmpty();
