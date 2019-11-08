# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magicmaze
DISTVERSION=	1_4_3_6
PORTREVISION=	4
CATEGORIES=	games ruby
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and low-tech monster-bashing maze game

LICENSE=	GPLv2+ RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING_GPL.txt

RUN_DEPENDS=	ruby${RUBY_SUFFIX}-sdl>=0:devel/ruby-sdl

USES=		sdl shebangfix
SHEBANG_FILES=	mm.rb testmm.rb
USE_SDL=	sdl image mixer
USE_RUBY=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	RUBY=${RUBY}

PORTDOCS=	*

DESKTOP_ENTRIES="Magic Maze" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data magicmaze" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/*.rb ${STAGEDIR}${DATADIR}
	${LN} -sf ../../${DATADIR_REL}/data/gfx/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${WRKSRC}/doc/BUGS.TXT \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
