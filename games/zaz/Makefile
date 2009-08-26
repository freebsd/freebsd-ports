# New ports collection makefile for:	zaz
# Date created:		25 Aug 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zaz
PORTVERSION=	0.2.8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A puzzle game where the player has to arrange balls in triplets

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		ftgl.2:${PORTSDIR}/graphics/ftgl

GNU_CONFIGURE=	yes
USE_SDL=	sdl image
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype2 -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/^zazdocdir =/ s|$${prefix}/doc|$${prefix}/share/doc|' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-zazdocDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
