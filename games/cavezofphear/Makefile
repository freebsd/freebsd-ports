PORTNAME=	cavezofphear
PORTVERSION=	0.6.2
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Boulder Dash / Digger-like game for consoles/terminals
WWW=		https://github.com/AMDmi3/cavezofphear

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man

USES=		cmake ncurses
USE_GITHUB=	true
GH_ACCOUNT=	AMDmi3
CMAKE_ON=	SYSTEMWIDE
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=share/man

DATADIR=	${PREFIX}/share/phear
PLIST_FILES=	bin/phear share/man/man6/phear.6.gz
PORTDOCS=	ChangeLog.md README.md TODO
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
