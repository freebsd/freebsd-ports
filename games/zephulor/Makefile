# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	zephulor
PORTVERSION=	1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/apz/apz/stable/
DISTNAME=	${PORTNAME}-source

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Side scrolling arcade game

LICENSE=	LGPL20

EXTRACT_DEPENDS=pngtopnm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt manual.txt readme-*.txt

DOCSRCDIR2=	${WRKSRC}/maptool
DOCSDIR2=	${DOCSDIR}/maptool
DOC_FILES2=	manual.txt

DESKTOP_ENTRIES="Adventures on Planet Zephulor" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" "false"

SUB_FILES=	${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|#!.*python|#!${PYTHON_CMD}|' \
		${WRKSRC}/*.py ${WRKSRC}/maptool/*.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-extract:
	@(cd ${WRKSRC}/data && ${LOCALBASE}/bin/pngtopnm zephulor.png | \
		${LOCALBASE}/bin/pamscale .1 | ${LOCALBASE}/bin/pnmtopng > zephulor1.png)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${MKDIR} ${DATADIR}/maptool
	${INSTALL_SCRIPT} ${WRKSRC}/maptool/*.py ${DATADIR}/maptool

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/zephulor1.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
