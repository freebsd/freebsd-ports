PORTNAME=	etuples
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.10
#MASTER_SITES=	PYPI # no tests
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python S-expression emulation using tuple-like objects
WWW=		https://github.com/pythological/etuples

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cons>0:devel/py-cons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multipledispatch>0:devel/py-multipledispatch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests fail: TypeError: Tried to dispatch on non-type, see https://github.com/pythological/etuples/issues/24

USE_GITHUB=	yes
GH_ACCOUNT=	pythological
GH_PROJECT=	etuples

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION="${PORTVERSION}"

NO_ARCH=	yes

.include <bsd.port.mk>
