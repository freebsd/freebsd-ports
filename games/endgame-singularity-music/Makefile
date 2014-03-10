# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	endgame-singularity-music
PORTVERSION=	006
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music pack for endgame-singularity

PROJECTHOST=	endgame-singularity
NO_BUILD=	yes
USES=		zip
DATADIR=	${PREFIX}/share/singularity

NO_STAGE=	yes
do-install:
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} music ${DATADIR}/

.include <bsd.port.mk>
