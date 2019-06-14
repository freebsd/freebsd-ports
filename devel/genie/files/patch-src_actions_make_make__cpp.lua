--- src/actions/make/make_cpp.lua.orig	2018-11-12 04:25:03 UTC
+++ src/actions/make/make_cpp.lua
@@ -435,11 +435,11 @@
 
 		_p('  ALL_CPPFLAGS       += $(CPPFLAGS) %s $(DEFINES) $(INCLUDES)', table.concat(cc.getcppflags(cfg), " "))
 
-		_p('  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cfg.buildoptions, cfg.buildoptions_asm)))
-		_p('  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cfg.buildoptions, cfg.buildoptions_c)))
-		_p('  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cc.getcxxflags(cfg), cfg.buildoptions, cfg.buildoptions_cpp)))
-		_p('  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cc.getobjcflags(cfg), cfg.buildoptions, cfg.buildoptions_objc)))
-		_p('  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH)%s', make.list(table.join(cc.getcflags(cfg), cc.getcxxflags(cfg), cc.getobjcflags(cfg), cfg.buildoptions, cfg.buildoptions_objcpp)))
+		_p('  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)%s', make.list(table.join(cc.getcflags(cfg), cfg.buildoptions, cfg.buildoptions_asm)))
+		_p('  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS)%s', make.list(table.join(cc.getcflags(cfg), cfg.buildoptions, cfg.buildoptions_c)))
+		_p('  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)%s', make.list(table.join(cc.getcflags(cfg), cc.getcxxflags(cfg), cfg.buildoptions, cfg.buildoptions_cpp)))
+		_p('  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS)%s', make.list(table.join(cc.getcflags(cfg), cc.getobjcflags(cfg), cfg.buildoptions, cfg.buildoptions_objc)))
+		_p('  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS)%s', make.list(table.join(cc.getcflags(cfg), cc.getcxxflags(cfg), cc.getobjcflags(cfg), cfg.buildoptions, cfg.buildoptions_objcpp)))
 
 		_p('  ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)%s',
 		        make.list(table.join(cc.getdefines(cfg.resdefines),
@@ -495,7 +495,7 @@
 			end
 		else
 			local tool = iif(cfg.language == "C", "CC", "CXX")
-			_p('  LINKCMD             = $(%s) -o $(TARGET) $(LINKOBJS) $(RESOURCES) $(ARCH) $(ALL_LDFLAGS) $(LIBS)', tool)
+			_p('  LINKCMD             = $(%s) -o $(TARGET) $(LINKOBJS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)', tool)
 		end
 	end
 
