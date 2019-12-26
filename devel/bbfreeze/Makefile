# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bbfreeze
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Module to create standalone executables from Python scripts

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	ZLIB

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}altgraph>=0.9:math/py-altgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bbfreeze-loader>=1.1.0:devel/bbfreeze-loader@${PY_FLAVOR}

USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/altgraph/s,==,>=,' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e '/from altgraph\.compat import/d' \
		${WRKSRC}/bbfreeze/modulegraph/modulegraph.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
