# Created by: Dominic Fandrey
# $FreeBSD$

PORTNAME=	oax
PORTVERSION=	B50
CATEGORIES=	games
MASTER_SITES=	http://files.poulsander.com/~poul19/public_files/eliminationSource/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	OpenArena Mod: OpenArena Xpanded

PLIST_SUB+=	DISTNAME="${DISTNAME}" \
		PORTNAME="${PORTNAME}"

NO_BUILD=	yes

OABASE=		${DISTNAME}

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})

.include "../openarena/Makefile.include"

.include <bsd.port.post.mk>
