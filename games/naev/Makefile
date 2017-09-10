# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	naev
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	2D action/RPG space game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libvorbisfile.so:audio/libvorbis \
		libzip.so:archivers/libzip \
		libcsparse.so:math/suitesparse
RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/${DISTNAME}-ndata.zip:games/naev-data

USES=		autoreconf:build compiler:features gmake pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GL=		gl glu
USE_GNOME=	libxml2

CONFIGURE_ARGS=	--with-ndata-path="${DATADIR}/${DISTNAME}-ndata.zip" \
		--enable-debug=no
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PORTDATA=	*
PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME} man/man6/${PORTNAME}.6.gz \
		share/applications/${PORTNAME}.desktop \
		share/appdata/${PORTNAME}.appdata.xml \
		share/pixmaps/${PORTNAME}.png

OPTIONS_DEFINE=	DOCS OPENAL SDL2 SDL_MIXER
OPTIONS_DEFAULT=	LUA_JIT OPENAL SDL2 SDL_MIXER
OPTIONS_SINGLE=		LUA
OPTIONS_SINGLE_LUA=	LUA_INTERNAL LUA_SHARED LUA_JIT

LUA_INTERNAL_DESC=	Use bundled Lua
LUA_INTERNAL_CONFIGURE_ON=	--enable-lua=internal
LUA_SHARED_DESC=	Use Lua from lang/lua51
LUA_SHARED_CONFIGURE_ON=	--enable-lua=shared
LUA_SHARED_USES=	lua:51
LUA_JIT_DESC=		Use LuaJIT from lang/luajit
LUA_JIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
OPENAL_USES=	openal
OPENAL_CONFIGURE_WITH=	openal
SDL_MIXER_DESC=	SDL_mixer sound backend
SDL_MIXER_CONFIGURE_WITH=	sdlmixer
SDL2_DESC=	Use SDL2 instead of SDL
SDL2_CONFIGURE_WITH=	sdl2
SDL2_USE=	SDL=sdl2
SDL2_USE_OFF=	SDL=sdl

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "gcc"
USE_GCC=	yes
.endif

.if ${PORT_OPTIONS:MSDL_MIXER}
.	if ${PORT_OPTIONS:MSDL2}
USE_SDL+=	mixer2
.	else
USE_SDL+=	mixer
.	endif
.endif

.include <bsd.port.post.mk>
