PORTNAME=	distlib
DISTVERSION=	0.3.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Low-level components of distutils2 and higher-level APIs
WWW=		https://github.com/pypa/distlib

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 3 tests fail, see https://github.com/pypa/distlib/issues/205

NO_ARCH=	yes

.include <bsd.port.mk>
