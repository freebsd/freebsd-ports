PORTNAME=	cavezofphear
PORTVERSION=	0.5.3
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Boulder Dash / Digger-like game for consoles/terminals

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake ncurses
USE_GITHUB=	true
GH_ACCOUNT=	AMDmi3
CMAKE_ON=	SYSTEMWIDE

DATADIR=	${PREFIX}/share/phear
PLIST_FILES=	bin/phear
PORTDOCS=	ChangeLog.md README.md TODO
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
