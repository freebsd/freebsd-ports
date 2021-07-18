PORTNAME=	zaz
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game where the player has to arrange balls in triplets

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libftgl.so:graphics/ftgl

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl image
USE_GL=		gl glu

CPPFLAGS+=	-I${LOCALBASE}/include/freetype2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-icondir="${PREFIX}/share/pixmaps"

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# Unconditially disable NLS for now: the game segfaults with 8bit locales
#.if ${PORT_OPTIONS:MNLS}
#USES+=		gettext
#PLIST_SUB+=	NLS=""
#.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
#.endif

post-patch:
	@${REINPLACE_CMD} -e '/^zazdocdir =/ s|$${prefix}/doc|$${prefix}/share/doc|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/PKG_CONFIG/ s|vorbisfile |&vorbis |' \
		${WRKSRC}/configure.ac ${WRKSRC}/configure

.include <bsd.port.mk>
