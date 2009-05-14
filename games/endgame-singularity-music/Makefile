# New ports collection makefile for:	endgame-singularity-music
# Date created:		10 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	endgame-singularity-music
PORTVERSION=	006
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE CENKES

MAINTAINER=	freebsd-ports@sslash.org.ua
COMMENT=	Music pack for endgame-singularity

PROJECTHOST=	endgame-singularity
NO_BUILD=	yes
USE_ZIP=	yes
DATADIR=	${PREFIX}/share/singularity

do-install:
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} music ${DATADIR}/

.include <bsd.port.mk>
