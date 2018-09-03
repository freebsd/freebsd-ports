Fix build with clang7:

	WeeklyTimesheet.cpp:287:37: error: default initialization of an object of const type 'const Lotsofcake::Configuration' requires a user-provided default constructor
	const Lotsofcake::Configuration configuration;

--- Charm/Lotsofcake/Configuration.h.orig	2018-09-03 18:53:17 UTC
+++ Charm/Lotsofcake/Configuration.h
@@ -36,6 +36,8 @@ namespace Lotsofcake {
 class Configuration
 {
 public:
+    Configuration();
+
     bool isConfigured() const;
 
     void importFromTaskExport(const TaskExport &exporter);
