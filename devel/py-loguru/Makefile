PORTNAME=	loguru
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python logging made (stupidly) simple
WWW=		https://loguru.readthedocs.io/en/stable/ \
		https://github.com/Delgan/loguru

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3<5:devel/py-flit-core@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CPE_VENDOR=	loguru_project

.include <bsd.port.mk>
