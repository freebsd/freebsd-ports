# New ports collection makefile for:	gmixer
# Version required:    0.98c
# Date created:        25 February 1999
# Whom:                Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.2 1999/04/06 09:36:42 jseger Exp $
#

DISTNAME=	gmixer-0.98c
CATEGORIES=	audio
MASTER_SITES=	http://junior.technion.ac.il/~sergey/linux/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

ALL_TARGET=	gmixer

pre-install:
	@ ${MKDIR} ${PREFIX}/share/pixmaps
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmixer ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/gmixer.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
