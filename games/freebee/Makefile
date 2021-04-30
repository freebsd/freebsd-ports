PORTNAME=	freebee
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.7
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multi-platform ncurses-based console client for Free Bee

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	freebee-game
GH_PROJECT=	console-client

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
