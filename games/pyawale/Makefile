# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyawale
PORTVERSION=	0.4.0
PORTREVISION=	8
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/pyawale/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYGAME}

USES=		python:2.7

SUB_FILES=	${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name '*.py' | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|'
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog LISEZMOI NEWS README \
		docs/*.rest docs/*.html docs/*.jpg" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
