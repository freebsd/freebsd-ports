# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	mopesnake
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-pc-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Classic snake game in which you attempt to eat all the pain

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	TODO.txt index.html

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Master Of Pain (Eating) - Snake" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/*.py ${WRKSRC}/mopelib/*.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images mopelib music sounds" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/doc/screenshot1.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/version ${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
