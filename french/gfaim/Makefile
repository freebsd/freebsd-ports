# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	gfaim
PORTVERSION=	0.30
PORTREVISION=	5
CATEGORIES=	french
MASTER_SITES=	http://freeperso.free.fr/ \
		http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		http://www.cultdeadsheep.org/FreeBSD/ports/download/distfiles/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Gfaim est un logiciel de recherche de recettes de cuisine

USE_GNOME=	gtk12

DATADIR?=	${PREFIX}/lib/gfaim
MAKE_ENV+=	DATADIR=${DATADIR}

PLIST_FILES=	bin/gfaim bin/imprec lib/gfaim/cuisine.dat \
		lib/gfaim/cuisine.idx
PLIST_DIRS=	lib/gfaim
PORTDOCS=	legal.txt lisezmoi.txt
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
