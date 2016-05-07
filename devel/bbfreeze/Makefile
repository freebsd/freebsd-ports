# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bbfreeze
PORTVERSION=	1.1.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Module to create standalone executables from Python scripts

LICENSE=	ZLIB

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}altgraph>=0.9:math/py-altgraph \
		${PYTHON_PKGNAMEPREFIX}bbfreeze-loader>=1.1.0:devel/bbfreeze-loader

USES=		python:2 zip
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/altgraph/s,==,>=,' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e '/from altgraph\.compat import/d' \
		${WRKSRC}/bbfreeze/modulegraph/modulegraph.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
