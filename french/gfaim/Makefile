# New ports collection makefile for:	gfaim
# Date created:		Monday 27 May 2002
# Whom:			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	gfaim
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	french misc
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		http://www.cultdeadsheep.org/FreeBSD/ports/download/distfiles/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Gfaim est un logiciel de recherche de recettes de cuisine

USE_X_PREFIX= 	yes
USE_GNOME=	gtk12

DATADIR?=	${PREFIX}/lib/gfaim
MAKE_ENV+=	DATADIR=${DATADIR}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gfaim

.include <bsd.port.mk>
