############################################################
CXX := c++
STRIP := strip
############################################################
MKDIR_CMD = test -d $(@D) || mkdir -p $(@D)
############################################################

SDL := ${LOCALBASE}
SDL_IMAGE := ${LOCALBASE}

CPPFLAGS += -I${SDL}/include/SDL -I${SDL}/include -I${SDL_IMAGE}/include/SDL
LDFLAGS += \
	-L${SDL_IMAGE}/lib -Wl,-rpath -Wl,${SDL_IMAGE}/lib \
	-L${SDL}/lib -Wl,-rpath -Wl,${SDL}/lib \
	-lSDL_image -lSDL -lSDLmain -pthread -lpng

prog:	Release/54321-$(OPSYS)

Release/54321-$(OPSYS):
	-@$(MKDIR_CMD)
	echo '#!/bin/sh' > $@
	echo "cd ./bin/$(OPSYS) && exec ./54321 \$$*" >> $@
	chmod 755 $@
