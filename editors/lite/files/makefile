CFLAGS+=	-Wall -Wextra
CPPFLAGS+=	-DLUA_USE_POSIX -I. \
		$(shell pkg-config --cflags lua-$(LUA_VER) sdl2)
LIBS=		$(shell pkg-config --libs lua-$(LUA_VER) sdl2)

lite_OBJS=	api/api.o \
		api/renderer.o \
		api/renderer_font.o \
		api/system.o \
		lib/stb/stb_truetype.o \
		main.o \
		rencache.o \
		renderer.o

CCACHE?=	$(shell command -v ccache)

%.o: %.c
	$(CCACHE) $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

lite: $(lite_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

all: lite

.PHONY: all install
