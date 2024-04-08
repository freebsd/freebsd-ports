PORTNAME=	watermark
PORTVERSION=	2.4.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	IPython magic function to print date/time stamps and various system information
WWW=		https://github.com/rasbt/watermark

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=1.4:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=6.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	GPU
GPU_DESC=	GPU (Graphic Processing Unit) support

GPU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py3nvml>=0.2:devel/py-py3nvml@${PY_FLAVOR}

.include <bsd.port.mk>
