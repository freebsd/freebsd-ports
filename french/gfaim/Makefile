# New ports collection makefile for:	gfaim
# Date created:		Monday 27 May 2002
# Whom:			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	gfaim
PORTVERSION=	0.30
CATEGORIES=	french misc
MASTER_SITES=	http://perso.club-internet.fr/lchretie/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Gfaim est un logiciel de recherche de recettes de cuisine

USE_X_PREFIX= 	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12

DATADIR?=	${PREFIX}/lib/gfaim
MAKE_ENV+=	DATADIR=${DATADIR}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gfaim

.include <bsd.port.mk>
