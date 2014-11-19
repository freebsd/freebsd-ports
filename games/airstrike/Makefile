# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	airstrike
PORTVERSION=	c7
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/
DISTNAME=	${PORTNAME}-pre6a-src_freebsd_and_v${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2d biplane dogfight game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-pre6a-src

USES=		gmake
USE_SDL=	image mixer sdl
ALL_TARGET=
INSTALLS_ICONS=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	ChangeLog README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	1.0-features 33fps.out BUGS WHISHLIST *.txt \
		collisions.tm design.dia design.pdf fun.ps

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} pkg-message

DESKTOP_ENTRIES="Airstrike" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS += -DLINUX|#CFLAGS += -DLINUX|' \
		-e '/$$(CC)/s/$$/ -lm/' \
		${WRKSRC}/src/Makefile
	@${FIND} ${WRKSRC} -name '*.c' -or -name '*.h' | ${XARGS} \
		${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g'

do-build:
	@(cd ${WRKSRC} && ${MAKE_CMD} airstrike-sound)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for d in data airstrikerc
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/data/balloon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
