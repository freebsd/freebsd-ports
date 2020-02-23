# Created by: Jan Stocker <Jan.Stocker@t-online.de>
# $FreeBSD$

PORTNAME=	thudboard
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.million.nl/file/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	The Discworld Boardgame Board

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

NO_WRKSUBDIR=	yes
USES=		python:2.7

SUB_FILES=	thudboard

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|file:.*/docs|file://${DOCSDIR}|' \
		${WRKSRC}/thud.py

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/thudboard ${STAGEDIR}${PREFIX}/bin/thudboard
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pyc ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.	for d in koomvalley img
	@${MKDIR} ${STAGEDIR}${DATADIR}/${d}
	@(cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${d})
.	endfor

.include <bsd.port.mk>
