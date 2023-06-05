PORTNAME=	pythonfinder
PORTVERSION=	2.0.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python discovery tool to help locate python on any system
WWW=		https://github.com/sarugaku/pythonfinder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.33.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cached-property>=0:devel/py-cached-property@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.10.7:devel/py-pydantic@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
