# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	naev
PORTVERSION=	0.6.1
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
RUN_DEPENDS=	${DATADIR}/ndata-${PORTVERSION}.zip:games/naev-data

USES=		autoreconf:build compiler:features gmake pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GL=		glu
USE_GNOME=	libxml2

CONFIGURE_ARGS=	--with-ndata-path="${DATADIR}/ndata-${PORTVERSION}.zip" \
		--enable-debug=no
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PORTDATA=	*
PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME} man/man6/naev.6.gz \
		share/applications/${PORTNAME}.desktop \
		share/appdata/${PORTNAME}.appdata.xml \
		share/pixmaps/${PORTNAME}.png

OPTIONS_DEFINE=	DOCS OPENAL SDL2 SDL_MIXER
OPTIONS_DEFAULT=	OPENAL SDL2 SDL_MIXER

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
