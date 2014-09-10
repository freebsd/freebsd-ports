# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magicmaze
PORTVERSION=	1.4.3.6
PORTREVISION=	3
CATEGORIES=	games ruby
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/./_/g}

MAINTAINER=	games@FreeBSD.org
COMMENT=	Simple and low-tech monster-bashing maze game

LICENSE=	GPLv2

RUN_DEPENDS=	ruby${RUBY_SUFFIX}-sdl>=0:${PORTSDIR}/devel/ruby-sdl

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/./_/g}

USES=		shebangfix
SHEBANG_FILES=	mm.rb testmm.rb
USE_SDL=	sdl image mixer
USE_RUBY=	yes
NO_BUILD=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.TXT

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	BUGS.TXT

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

	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
