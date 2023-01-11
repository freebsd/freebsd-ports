PORTNAME=	hupper
PORTVERSION=	1.10.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Integrated process monitor for developing and reloading daemons
WWW=		https://docs.pylonsproject.org/projects/hupper/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>0:devel/py-watchdog@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
