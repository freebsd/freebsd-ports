# $FreeBSD$

PORTNAME=	krank
PORTVERSION=	07
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Little casual game

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME} \
		${PYNUMPY}

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGELOG.txt README

DESKTOP_ENTRIES="Krank" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -name .cvsignore -type f -print0 -or -name .DS_Store -type f -print0 | \
		${XARGS} -0 ${RM} -rf

post-patch:
	${REINPLACE_CMD} -e 's|`dirname.*|${DATADIR}|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/krank ${PREFIX}/bin

	${MKDIR} ${DATADIR}
.for d in art fonts html levels sounds src
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor
	${INSTALL_DATA} ${WRKSRC}/krank.iss ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.xcf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/html/gfx/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
