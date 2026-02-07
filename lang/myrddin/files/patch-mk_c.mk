--- mk/c.mk.orig	2020-04-02 20:13:20 UTC
+++ mk/c.mk
@@ -9,7 +9,7 @@ _LIBINCPATHS=$(addprefix -I, $(dir $(DEPS))) $(_PCHDRS
 _LIBPATHS=$(addprefix -l, $(patsubst lib%.a,%,$(notdir $(DEPS)))) $(_PCLIBS)
 
 # yeah, I should probably remove -Werror, but it's nice for developing alone.
-CFLAGS += -Wall -Werror -Wno-unused-parameter -Wno-missing-field-initializers -Wno-sign-compare -Wno-char-subscripts -g -O0
+CFLAGS += -Wall -Wno-unused-parameter -Wno-missing-field-initializers -Wno-sign-compare -Wno-char-subscripts -g -O0
 CFLAGS += -MMD -MP -MF .deps/$(subst /,-,$*).d
 
 LIB ?= $(INSTLIB)
