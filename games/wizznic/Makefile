# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wizznic
PORTVERSION=	380
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Source%20Releases/
DISTNAME=	Wizznic_src_build_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Implementation of the arcade classic Puzznic

LICENSE=	GPLv3+

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake sdl tar:bzip2
USE_SDL=	image mixer sdl
MAKE_ENV=	DATADIR=${DATADIR}/
MAKEFILE=	Makefile.linux

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/wizznic man/man6/wizznic.6.gz

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
	${INSTALL_MAN} ${WRKSRC}/doc/wizznic.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
.for f in changelog.txt credits.txt music-score-credits.txt ports.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
