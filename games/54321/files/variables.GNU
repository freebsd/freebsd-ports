############################################################
CXX := c++
STRIP := strip
############################################################
MKDIR_CMD = test -d $(@D) || mkdir -p $(@D)
############################################################

SDL := /usr/local
SDL_IMAGE := /usr/local

CPPFLAGS += -I${SDL}/include/SDL11 -I${SDL_IMAGE}/include/SDL11
LDFLAGS += \
	-L${SDL_IMAGE}/lib -Wl,-rpath -Wl,${SDL_IMAGE}/lib \
	-L${SDL}/lib -Wl,-rpath -Wl,${SDL}/lib \
	-lSDL_image -lSDL-1.1 -lSDLmain-1.1 -pthread -lpng

prog:	Release/54321-$(OPSYS)

Release/54321-$(OPSYS):
	-@$(MKDIR_CMD)
	echo '#!/bin/sh' > $@
	echo "cd ./bin/$(OPSYS) && exec ./54321 \$$*" >> $@
	chmod 755 $@
