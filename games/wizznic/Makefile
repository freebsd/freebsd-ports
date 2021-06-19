# Created by: Rusmir Dusko <nemysis@FreeBSD.org>

PORTNAME=	wizznic
PORTVERSION=	1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Implementation of the arcade classic Puzznic

LICENSE=	GPLv3+

LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	DusteDdk
GH_PROJECT=	Wizznic

USES=		gmake sdl tar:bzip2
USE_SDL=	image mixer sdl
MAKE_ENV=	DATADIR=${DATADIR}/
MAKEFILE=	Makefile.linux

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/wizznic share/man/man6/wizznic.6.gz

DESKTOP_ENTRIES="Wizznic!" "" "${DATADIR}/packs/001_wizznic/icon.png" \
		"${PORTNAME}" "Game;LogicGame;" false

OPTIONS_DEFINE=	OPENGL DOCS
OPTIONS_DEFAULT=OPENGL
OPENGL_USES=	gl
OPENGL_USE=	GL=gl
OPENGL_MAKE_ENV_OFF=	WITH_OPENGL=false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wizznic ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data packs" ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/wizznic.6 ${STAGEDIR}${MAN6PREFIX}/share/man/man6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
.for f in changelog.txt credits.txt music-score-credits.txt ports.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
