--- Makefile.PL.orig	Tue Feb 18 13:55:16 2003
+++ Makefile.PL	Tue May 13 14:17:53 2003
@@ -49,4 +49,39 @@
 	# Un-comment this if you add C files to link with later:
     # 'OBJECT'		=> '$(O_FILES)', # link all the C files too
     'clean'             => {FILES => "*.tar.gz *.ppd pod2htm*"},
+    'MAN3PODS' => {
+	'lib/Log/Log4perl.pm' => '$(INST_MAN3DIR)/Log::Log4perl.$(MAN3EXT)',
+	'lib/Log/Log4perl/Appender.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Appender.$(MAN3EXT)',
+	'lib/Log/Log4perl/Appender/DBI.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Appender::DBI.$(MAN3EXT)',
+	'lib/Log/Log4perl/Appender/TestArrayBuffer.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Appender::TestArrayBuffer.$(MAN3EXT)',
+	'lib/Log/Log4perl/Appender/TestBuffer.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Appender::TestBuffer.$(MAN3EXT)',
+	'lib/Log/Log4perl/Config.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Config.$(MAN3EXT)',
+	'lib/Log/Log4perl/Config/DOMConfigurator.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Config::DOMConfigurator.$(MAN3EXT)',
+	'lib/Log/Log4perl/Config/PropertyConfigurator.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Config::PropertyConfigurator.$(MAN3EXT)',
+	'lib/Log/Log4perl/Config/Watch.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Config::Watch.$(MAN3EXT)',
+	'lib/Log/Log4perl/DateFormat.pm' => '$(INST_MAN3DIR)/Log::Log4perl::DateFormat.$(MAN3EXT)',
+	'lib/Log/Log4perl/FAQ.pm' => '$(INST_MAN3DIR)/Log::Log4perl::FAQ.$(MAN3EXT)',
+	'lib/Log/Log4perl/Filter.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Filter.$(MAN3EXT)',
+	'lib/Log/Log4perl/Filter/Boolean.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Filter::Boolean.$(MAN3EXT)',
+	'lib/Log/Log4perl/Filter/LevelMatch.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Filter::LevelMatch.$(MAN3EXT)',
+	'lib/Log/Log4perl/Filter/LevelRange.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Filter::LevelRange.$(MAN3EXT)',
+	'lib/Log/Log4perl/Filter/StringMatch.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Filter::StringMatch.$(MAN3EXT)',
+	'lib/Log/Log4perl/JavaMap.pm' => '$(INST_MAN3DIR)/Log::Log4perl::JavaMap.$(MAN3EXT)',
+	'lib/Log/Log4perl/JavaMap/ConsoleAppender.pm' => '$(INST_MAN3DIR)/Log::Log4perl::JavaMap::ConsoleAppender.$(MAN3EXT)',
+	'lib/Log/Log4perl/JavaMap/FileAppender.pm' => '$(INST_MAN3DIR)/Log::Log4perl::JavaMap::FileAppender.$(MAN3EXT)',
+	'lib/Log/Log4perl/JavaMap/JDBCAppender.pm' => '$(INST_MAN3DIR)/Log::Log4perl::JavaMap::JDBCAppender.$(MAN3EXT)',
+	'lib/Log/Log4perl/JavaMap/NTEventLogAppender.pm' => '$(INST_MAN3DIR)/Log::Log4perl::JavaMap::NTEventLogAppender.$(MAN3EXT)',
+	'lib/Log/Log4perl/JavaMap/RollingFileAppender.pm' => '$(INST_MAN3DIR)/Log::Log4perl::JavaMap::RollingFileAppender.$(MAN3EXT)',
+	'lib/Log/Log4perl/JavaMap/SyslogAppender.pm' => '$(INST_MAN3DIR)/Log::Log4perl::JavaMap::SyslogAppender.$(MAN3EXT)',
+	'lib/Log/Log4perl/JavaMap/TestBuffer.pm' => '$(INST_MAN3DIR)/Log::Log4perl::JavaMap::TestBuffer.$(MAN3EXT)',
+	'lib/Log/Log4perl/Layout.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Layout.$(MAN3EXT)',
+	'lib/Log/Log4perl/Layout/NoopLayout.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Layout::NoopLayout.$(MAN3EXT)',
+	'lib/Log/Log4perl/Layout/PatternLayout.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Layout::PatternLayout.$(MAN3EXT)',
+	'lib/Log/Log4perl/Layout/SimpleLayout.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Layout::SimpleLayout.$(MAN3EXT)',
+	'lib/Log/Log4perl/Level.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Level.$(MAN3EXT)',
+	'lib/Log/Log4perl/Logger.pm' => '$(INST_MAN3DIR)/Log::Log4perl::Logger.$(MAN3EXT)',
+	'lib/Log/Log4perl/MDC.pm' => '$(INST_MAN3DIR)/Log::Log4perl::MDC.$(MAN3EXT)',
+	'lib/Log/Log4perl/NDC.pm' => '$(INST_MAN3DIR)/Log::Log4perl::NDC.$(MAN3EXT)'
+    },
 );
+
