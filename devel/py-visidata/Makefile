PORTNAME=	visidata
PORTVERSION=	2.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal interface for exploring and arranging tabular data
WWW=		https://github.com/saulpw/visidata

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.gpl3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
