# New ports collection makefile for: gif2png
# Version required:     0.6
# Date created:         30 Aug 1999
# Whom:                 saper@system.pl
#
# $FreeBSD$
#

DISTNAME=       gif2png-0.6
CATEGORIES=	graphics
MASTER_SITES=   ftp://swrinde.nde.swri.edu/pub/png/applications/

MAINTAINER=     saper@system.pl

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/gif2png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gif2png ${PREFIX}/bin

.include <bsd.port.mk>
