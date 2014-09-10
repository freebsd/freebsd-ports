# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flare
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-game/Linux/
DISTNAME=	${PORTNAME}-game.${PORTVERSION}
PKGNAMESUFFIX=	-game

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine

LICENSE=	GPLv3

RUN_DEPENDS=	flare:${PORTSDIR}/games/flare-engine

USES=		cmake
CMAKE_BUILD_TYPE=	#empty
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DBINDIR="bin" -DDATADIR="share/flare"

PORTDOCS=	*
PORTDATA=	*

DATADIR=	${PREFIX}/share/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
