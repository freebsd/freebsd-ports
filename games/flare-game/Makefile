# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flare
PORTVERSION=	1.05
DISTVERSIONPREFIX=	v
CATEGORIES=	games
PKGNAMESUFFIX=	-game

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine: game data

LICENSE=	CC-BY-SA-3.0

RUN_DEPENDS=	flare:games/flare-engine

USE_GITHUB=	yes
GH_ACCOUNT=	clintbellanger
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

USES=		cmake
CMAKE_BUILD_TYPE=	#empty
INSTALLS_ICONS=	yes
NO_ARCH=	yes

CMAKE_ARGS=	-DBINDIR="bin" -DDATADIR="share/flare"

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	share/appdata/org.flarerpg.Flare.appdata.xml

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
