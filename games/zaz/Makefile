# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zaz
PORTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game where the player has to arrange balls in triplets

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libtheora.so:${PORTSDIR}/multimedia/libtheora \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libftgl.so:${PORTSDIR}/graphics/ftgl

USES=		tar:bzip2 pkgconfig
GNU_CONFIGURE=	yes
USE_SDL=	sdl image
USE_GL=		gl glu

CPPFLAGS+=	-I${LOCALBASE}/include/freetype2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
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
