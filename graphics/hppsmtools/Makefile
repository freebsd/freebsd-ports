# New ports collection makefile for: 	hppsmtools
# Date created:		2 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	hppsmtools
PORTVERSION=	1.02
CATEGORIES=	graphics
MASTER_SITES=	http://unimut.fsk.uni-heidelberg.de/demi/photosmart/

MAINTAINER=	ports@FreeBSD.org

do-install:
.for file in psmdel psmdir psmget psmsho
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
