PORTNAME=	flare
PORTVERSION=	1.14
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games
PKGNAMESUFFIX=	-engine

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine
WWW=		https://flarerpg.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:env sdl
USE_GITHUB=	yes
GH_ACCOUNT=	flareteam
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}
USE_SDL=	sdl2 mixer2 image2 ttf2
CMAKE_BUILD_TYPE=	#empty

CMAKE_ARGS=	-DBINDIR="bin" -DDATADIR="share/flare"

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/flare

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.engine.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
