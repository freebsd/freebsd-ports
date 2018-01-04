# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bouncy
PORTVERSION=	r6
PORTREVISION=	4
CATEGORIES=	games python
MASTER_SITES=	http://media.pyweek.org/dl/3/bouncy/ \
		SF/nemysisfreebsdp/games/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-post-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-post-${DISTVERSION}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	You are a hungry rabbit. Eat food to complete the level

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL.txt

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR}

WRKSRC=		${WRKDIR}/${PORTNAME}-post-${DISTVERSION}

USES=		python:2

PORTDOCS=	README.txt

INSTALLS_ICONS=	yes

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Bouncy the Hungry Rabbit" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS SHADER
OPTIONS_DEFAULT=SHADER

SHADER_DESC=	Hardware shader support

post-patch:
	@${FIND} ${WRKSRC} -name '*.py' | ${XARGS} \
		${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|'
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-patch-SHADER-on:
	@${REINPLACE_CMD} -i '' '/#try/,/#    print/s/#//' ${WRKSRC}/objects.py

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in data pyglyph
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
