# New ports collection makefile for:	optipng
# Date created:				09 July 2003
# Whom:					Thomas Hurst <freaky@aagh.net>
#
# $FreeBSD$
#

PORTNAME=	optipng
PORTVERSION=	0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.toronto.edu/~cosmin/pngtech/optipng/

MAINTAINER=	freaky@aagh.net
COMMENT=	An optimizer for PNG files

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	scripts/Makefile.gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/optipng ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}

.for i in CAVEAT DESIGN FEATURES HISTORY LICENSE README TODO USAGE index.html
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
