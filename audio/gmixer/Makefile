# New ports collection makefile for:	gmixer
# Version required:    0.98c
# Date created:        25 February 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.3 1999/05/29 03:55:31 steve Exp $
#

DISTNAME=	gmixer-0.98c
CATEGORIES=	audio
MASTER_SITES=	http://junior.technion.ac.il/~sergey/linux/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

ALL_TARGET=	gmixer

pre-install:
	@ ${MKDIR} ${PREFIX}/share/pixmaps
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmixer ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/gmixer.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
