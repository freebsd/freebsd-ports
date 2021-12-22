# Created by: arved

PORTNAME=	qnetwalk
PORTVERSION=	1.7.0
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Game for system administrators

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3

USES=		cmake compiler:c++11-lang pkgconfig qt:5 sdl
USE_QT=		core gui widgets qmake_build buildtools_build linguisttools_build
USE_SDL=	sdl2 mixer2

PORTDOCS=	ChangeLog.md README.md
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
