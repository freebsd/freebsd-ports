PORTNAME=	freebee
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	2.0
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

PLIST_FILES=	bin/freebee share/man/man6/freebee.6.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
