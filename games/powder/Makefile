PORTNAME=	powder
PORTVERSION=	118
CATEGORIES=	games
MASTER_SITES=	http://www.zincland.com/powder/release/ \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical dungeon crawling game

LICENSE=	POWDER
LICENSE_NAME=	THE POWDER LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		gmake sdl
USE_SDL=	sdl
USE_CXXSTD=	c++98

PLIST_FILES=	bin/powder
PORTDOCS=	README.TXT CREDITS.TXT

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} buildall.sh

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/powder ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
