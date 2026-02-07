--- src/actions/make/make_cpp.lua.orig	2023-09-20 17:46:05 UTC
+++ src/actions/make/make_cpp.lua
@@ -225,9 +225,8 @@ --
 		_p('endif')
 		_p('')
 
-		_p('ifndef verbose')
-		_p('  SILENT = @')
-		_p('endif')
+		_p('verbose=1')
+		_p('SILENT =')
 		_p('')
 
 		-- identify the shell type
@@ -254,11 +253,6 @@ --
 		_p('endif')
 		_p('')
 
-		_p('CC  = %s', cc.cc)
-		_p('CXX = %s', cc.cxx)
-		_p('AR  = %s', cc.ar)
-		_p('')
-
 		_p('ifndef RESCOMP')
 		_p('  ifdef WINDRES')
 		_p('    RESCOMP = $(WINDRES)')
@@ -423,11 +417,11 @@ --
 
 		_p('  ALL_CPPFLAGS       += $(CPPFLAGS) %s $(DEFINES) $(INCLUDES)', table.concat(cc.getcppflags(cfg), " "))
 
-		_p('  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cfg.buildoptions, cfg.buildoptions_asm)))
-		_p('  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cfg.buildoptions, cfg.buildoptions_c)))
-		_p('  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cc.getcxxflags(cfg), cfg.buildoptions, cfg.buildoptions_cpp)))
-		_p('  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cc.getobjcflags(cfg), cfg.buildoptions, cfg.buildoptions_objc)))
-		_p('  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cc.getcxxflags(cfg), cc.getobjcflags(cfg), cfg.buildoptions, cfg.buildoptions_objcpp)))
+		_p('  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) %s', make.list(table.join(cc.getcflags(cfg), cfg.buildoptions, cfg.buildoptions_asm)))
+		_p('  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) %s', make.list(table.join(cc.getcflags(cfg), cfg.buildoptions, cfg.buildoptions_c)))
+		_p('  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) %s', make.list(table.join(cc.getcflags(cfg), cc.getcxxflags(cfg), cfg.buildoptions, cfg.buildoptions_cpp)))
+		_p('  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) %s', make.list(table.join(cc.getcflags(cfg), cc.getobjcflags(cfg), cfg.buildoptions, cfg.buildoptions_objc)))
+		_p('  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) %s', make.list(table.join(cc.getcflags(cfg), cc.getcxxflags(cfg), cc.getobjcflags(cfg), cfg.buildoptions, cfg.buildoptions_objcpp)))
 
 		_p('  ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)%s',
 		        make.list(table.join(cc.getdefines(cfg.resdefines),
@@ -467,7 +461,7 @@ --
 			lddeps  = libdeps
 		end
 
-		_p('  ALL_LDFLAGS        += $(LDFLAGS)%s', make.list(table.join(cc.getlibdirflags(cfg), cc.getldflags(cfg), cfg.linkoptions)))
+		_p('  ALL_LDFLAGS        += --verbose $(LDFLAGS)%s', make.list(table.join(cc.getlibdirflags(cfg), cc.getldflags(cfg), cfg.linkoptions)))
 		_p('  LIBDEPS            +=%s', libdeps)
 		_p('  LDDEPS             +=%s', lddeps)
 
@@ -497,7 +491,7 @@ --
 				startgroup = '-Wl,--start-group '
 				endgroup   = ' -Wl,--end-group'
 			end
-			_p('  LINKCMD             = $(%s) -o $(TARGET) $(LINKOBJS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) %s$(LIBS)%s', tool, startgroup, endgroup)
+			_p('  LINKCMD             = $(%s) -o $(TARGET) $(LINKOBJS) $(RESOURCES) $(ALL_LDFLAGS) %s$(LIBS)%s', tool, startgroup, endgroup)
 		end
 	end
 
