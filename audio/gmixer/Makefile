# New ports collection makefile for:	gmixer
# Version required:    0.98c
# Date created:        25 February 1999
# Whom:                Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	gmixer-0.98c
CATEGORIES=	audio
MASTER_SITES=	http://junior.technion.ac.il/~sergey/linux/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel

ALL_TARGET=	gmixer

pre-install:
	@ ${MKDIR} ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
