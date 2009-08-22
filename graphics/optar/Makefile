# New ports collection makefile for:   optar
# Date created:        27 September 2008
# Whom:                antonakis@gmail.com
#
# $FreeBSD$
#

PORTNAME=	optar
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://xps.crucible.gr/
DISTFILES=	optar.tgz \
		font.h
EXTRACT_ONLY=	optar.tgz

MAINTAINER=	antonakis@gmail.com
COMMENT=	A tool for encoding data on paper

BUILD_DEPENDS=	${LOCALBASE}/include/libpng/png.h:${PORTSDIR}/graphics/png
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/optar

PLIST_FILES=	bin/optar bin/unoptar bin/pgm2ps

post-extract:
	@${RM} -v ${WRKSRC}/font.h
	@${CP} -v ${DISTDIR}/font.h ${WRKSRC}/font.h

.include <bsd.port.mk>
