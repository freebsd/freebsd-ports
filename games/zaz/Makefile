# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zaz
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A puzzle game where the player has to arrange balls in triplets

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		theora:${PORTSDIR}/multimedia/libtheora \
		vorbis:${PORTSDIR}/audio/libvorbis \
		ftgl:${PORTSDIR}/graphics/ftgl

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl image
USE_GL=		gl glu

CPPFLAGS+=	-I${LOCALBASE}/include/freetype2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-icondir="${PREFIX}/share/pixmaps"

PORTDOCS=	*

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
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
