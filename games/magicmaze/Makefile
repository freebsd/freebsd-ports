# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magicmaze
PORTVERSION=	1.4.3.6
PORTREVISION=	4
CATEGORIES=	games ruby
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and low-tech monster-bashing maze game

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING_GPL.txt

RUN_DEPENDS=	ruby${RUBY_SUFFIX}-sdl>=0:devel/ruby-sdl

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/./_/g}

USES=		shebangfix
SHEBANG_FILES=	mm.rb testmm.rb
USE_SDL=	sdl image mixer
USE_RUBY=	yes
NO_BUILD=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}
SUB_LIST=	RUBY=${RUBY}

DESKTOP_ENTRIES="Magic Maze" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data magicmaze" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/*.rb ${STAGEDIR}${DATADIR}

	${LN} -sf ${DATADIR}/data/gfx/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	cd ${WRKSRC} && ${COPYTREE_SHARE} "README.TXT doc/BUGS.TXT" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
