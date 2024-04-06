PORTNAME=	serializable
DISTVERSION=	0.4.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Base class with serialization helpers for user-defined Python objects
WWW=		https://github.com/openvax/serializable

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typechecks>=0.0.2:devel/py-typechecks@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # files required for tests are missing, see https://github.com/openvax/serializable/issues/9

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
