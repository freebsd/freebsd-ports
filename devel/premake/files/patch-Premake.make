--- Premake.make.orig	Tue Feb 24 21:49:57 2004
+++ Premake.make	Thu Mar 25 21:03:11 2004
@@ -8,13 +8,13 @@
 TARGET =
 
 ifeq ($(CONFIG),Debug)
-  CFLAGS += --no-rtti --no-exceptions
-  LDFLAGS += -ldl
+  CFLAGS += --no-exceptions
+  LDFLAGS +=
   TARGET = premake
 endif
 ifeq ($(CONFIG),Release)
-  CFLAGS += --no-rtti --no-exceptions -Os
-  LDFLAGS += -ldl
+  CFLAGS += --no-exceptions -Os
+  LDFLAGS +=
   TARGET = premake
 endif
 CXXFLAGS=$(CFLAGS)
@@ -23,37 +23,21 @@
 	-@if [ ! -d obj ]; then mkdir obj; fi
 	@echo $(notdir $<)
 	@$(CXX) $(CXXFLAGS) -MD -o $@ -c $<
-	@cp obj/$*.d obj/$*.P; \
-	 sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-	 -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d >> obj/$*.P; \
-	rm -f obj/$*.d
 
 obj/%.o : %.cpp
 	-@if [ ! -d obj ]; then mkdir obj; fi
 	@echo $(notdir $<)
 	@$(CXX) $(CXXFLAGS) -MD -o $@ -c $<
-	@cp obj/$*.d obj/$*.P; \
-	 sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-	 -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d >> obj/$*.P; \
-	rm -f obj/$*.d
 
 obj/%.o : %.cxx
 	-@if [ ! -d obj ]; then mkdir obj; fi
 	@echo $(notdir $<)
 	@$(CXX) $(CXXFLAGS) -MD -o $@ -c $<
-	@cp obj/$*.d obj/$*.P; \
-	 sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-	 -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d >> obj/$*.P; \
-	rm -f obj/$*.d
 
 obj/%.o : %.c
 	-@if [ ! -d obj ]; then mkdir obj; fi
 	@echo $(notdir $<)
 	@$(CC) $(CFLAGS) -MD -o $@ -c $<
-	@cp obj/$*.d obj/$*.P; \
-	 sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-	 -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d >> obj/$*.P; \
-	rm -f obj/$*.d
 
 OBJECTS = \
 	obj/premake.o \
