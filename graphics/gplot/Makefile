# New ports collection makefile for:    Gplot
# Date created:         26 Dec 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	gplot
PORTVERSION=	4.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.psc.edu/pub/gplot/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic utilities for the processing of CGM metafiles

NO_WRKSUBDIR=	yes
ALL_TARGET=	drawcgm gtex gplot
MAN1=		gplot.1
DOCS=		gplot.hlp gplot.txt gtex.doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplot ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gtex ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/drawcgm/drawcgm.a ${PREFIX}/lib/libcgm.a
	${INSTALL_MAN} ${WRKSRC}/gplot.man ${PREFIX}/man/man1/gplot.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/Gplot
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/Gplot
	${GZIP_CMD} ${PREFIX}/share/doc/Gplot/$f
.endfor
.endif

.include <bsd.port.mk>
