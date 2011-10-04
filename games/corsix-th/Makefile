# New ports collection makefile for:	CorsixTH
# Date created:				24 Nov 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	corsixth
DISTVERSION=	0.Beta8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	corsix-th
DISTNAME=	CorsixTH-${DISTVERSION:S/0.//}-Source

MAINTAINER=	mad@madpilot.net
COMMENT=	Open source clone of Theme Hospital

LICENSE=	MIT

RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_CMAKE=	yes
USE_LUA=	yes
USE_SDL=	mixer
WRKSRC=		${WRKDIR}/CorsixTH

post-patch:
# Allow the game to find its resources without wrapper scripts
	@${REINPLACE_CMD} -e \
		'/return loadfile/s,name,\\"${DATADIR}/\\" .. &,' \
			${WRKSRC}/CorsixTH/Src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CorsixTH/CorsixTH ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CorsixTH/CorsixTH.lua ${DATADIR}
	cd ${WRKSRC}/CorsixTH && ${COPYTREE_SHARE} "Bitmap Levels Lua" \
		${DATADIR}

.include <bsd.port.mk>
