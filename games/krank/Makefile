# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	krank
PORTVERSION=	07
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
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

post-extract:
	@${FIND} ${WRKSRC} -name .cvsignore -delete -or -name .DS_Store -delete

post-patch:
	${REINPLACE_CMD} -e 's|`dirname.*|${DATADIR}|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/krank ${STAGEDIR}${PREFIX}/bin/

.for d in art fonts html levels sounds src
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_DATA} ${WRKSRC}/krank.iss ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.xcf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/html/gfx/logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
