PORTNAME=	flare
PORTVERSION=	1.11
DISTVERSIONPREFIX=	v
CATEGORIES=	games
PKGNAMESUFFIX=	-game

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine: game data

LICENSE=	CC-BY-SA-3.0

RUN_DEPENDS=	flare:games/flare-engine

USE_GITHUB=	yes
GH_ACCOUNT=	flareteam
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

USES=		cmake gnome
CMAKE_BUILD_TYPE=	#empty
INSTALLS_ICONS=	yes
NO_ARCH=	yes

CMAKE_ARGS=	-DBINDIR="bin" -DDATADIR="share/flare"

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	share/metainfo/org.flarerpg.Flare.appdata.xml

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
