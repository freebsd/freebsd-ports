# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	endgame-singularity-music
PORTVERSION=	007
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	endgame-singularity

MAINTAINER=	mokhi64@gmail.com
COMMENT=	Music pack for endgame-singularity

NO_ARCH=	yes
NO_BUILD=	yes

USES=		zip

DATADIR=	${PREFIX}/share/singularity

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.ogg win lose" ${STAGEDIR}${DATADIR}/music

.include <bsd.port.mk>
