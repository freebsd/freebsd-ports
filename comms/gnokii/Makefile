# New ports collection makefile for:    gnokii
# Date created:         15 March 1999
# Whom:                 staffanu
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.2.3
CATEGORIES=	comms
MASTER_SITES=	ftp://multivac.fatburen.org/pub/gnokii/ \
		ftp://multivac.fatburen.org/pub/gnokii/old/

MAINTAINER=	staffanu@nada.kth.se

USE_GMAKE=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/gnokii ${PREFIX}/bin/gnokii

post-install:
	strip ${PREFIX}/bin/gnokii

.include <bsd.port.mk>
