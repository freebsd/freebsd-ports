# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	gplot
PORTVERSION=	4.3
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.psc.edu/pub/gplot/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic utilities for the processing of CGM metafiles

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

OPTIONS_DEFINE=	DOCS

CFLAGS+=	-Wno-return-type
NO_WRKSUBDIR=	yes
ALL_TARGET=	drawcgm gtex gplot
PORTDOCS=	gplot.hlp gplot.txt gtex.doc
USES=		fortran tar:Z

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplot ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gtex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/drawcgm/drawcgm.a ${STAGEDIR}${PREFIX}/lib/libcgm.a
	${INSTALL_MAN} ${WRKSRC}/gplot.man ${STAGEDIR}${PREFIX}/man/man1/gplot.1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
