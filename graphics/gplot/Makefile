# New ports collection makefile for:    Gplot
# Version required:     4.3
# Date created:         26 Dec 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $Id$
#

DISTNAME=	gplot
PKGNAME=	gplot-4.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.psc.edu/pub/gplot/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	giffunip@asme.org

NO_WRKSUBDIR=	yes

ALL_TARGET=	drawcgm gtex gplot
MAN1=		gplot.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplot ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gtex ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/drawcgm/drawcgm.a ${PREFIX}/lib/libcgm.a
	${INSTALL_MAN} ${WRKSRC}/gplot.man ${PREFIX}/man/man1/gplot.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/Gplot
	${GZIP_CMD} ${WRKSRC}/gplot.hlp
	${GZIP_CMD} ${WRKSRC}/gplot.txt
	${GZIP_CMD} ${WRKSRC}/gtex.doc
	${INSTALL_DATA} ${WRKSRC}/*.gz ${PREFIX}/share/doc/Gplot
.endif

.include <bsd.port.mk>
