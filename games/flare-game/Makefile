PORTNAME=	flare
PORTVERSION=	1.14
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games
PKGNAMESUFFIX=	-game

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine: game data
WWW=		https://flarerpg.org/

LICENSE=	CC-BY-SA-3.0

RUN_DEPENDS=	flare:games/flare-engine

USES=		cmake gnome
USE_GITHUB=	yes
GH_ACCOUNT=	flareteam
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}
CMAKE_BUILD_TYPE=	#empty
NO_ARCH=	yes
INSTALL_TARGET=	install

CMAKE_ARGS=	-DBINDIR="bin" -DDATADIR="share/flare"

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	share/metainfo/org.flarerpg.Flare.appdata.xml

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
