PORTNAME=	hijri-converter
DISTVERSION=	2.3.2.post1
CATEGORIES=	arabic python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hijri_converter-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hijri-Gregorian dates converter based on the Umm al-Qura calendar
WWW=		https://hijri-converter.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 2.3.2.post1: 64 passed

.include <bsd.port.mk>
