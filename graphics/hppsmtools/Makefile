# New ports collection makefile for: 	hppsmtools
# Date created:		2 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	hppsmtools
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://unimut.fsk.uni-heidelberg.de/demi/photosmart/ \
		http://atreides.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Tool for HP PhotoSmart C5340A & Konica Q-EZ digital cameras

ALL_TARGET=

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/psmget ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/psmdir ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/psmdel ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/psmsho ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/hppsmtools
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/hppsmtools/
.endif

.include <bsd.port.mk>
