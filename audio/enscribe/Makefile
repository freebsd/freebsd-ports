# New ports collection makefile for:	enscribe
# Date created:			15 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		enscribe
PORTVERSION=		0.0.4
CATEGORIES=		audio graphics
MASTER_SITES=		http://www.coppercloudmusic.com/enscribe/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		Create digital audio watermark images from photographic images

LIB_DEPENDS=		gd:${PORTSDIR}/graphics/gd \
			png:${PORTSDIR}/graphics/png \
			jpeg:${PORTSDIR}/graphics/jpeg \
			freetype:${PORTSDIR}/print/freetype2 \
			sndfile:${PORTSDIR}/audio/libsndfile

do-build:
	cd ${BUILD_WRKSRC}; ${CC} ${CFLAGS} \
		`pkg-config --cflags --libs sndfile freetype2` \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-lgd -lpng -ljpeg -lm -lz \
		-o enscribe enscribe.c

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/enscribe ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
