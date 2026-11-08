PORTNAME=	PyPubSub
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.7
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Publish-Subscribe Package
WWW=		https://github.com/schollii/pypubsub

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	schollii
GH_PROJECT=	pypubsub

NO_ARCH=	yes

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests/suite
TEST_ARGS=	-p no:black -p no:mypy -p no:cov -p no:benchmark -p no:xdist -p no:randomly \
		test1_listener.py test2_spec.py test2a_topic.py test2b_topicmgr.py \
		test2c_notify.py test2c_notify2.py test2d_except.py test3b_sel_default.py \
		test3c_pubsub3.py test3d_defaultlog.py test4_prov_module_expect.py \
		test4_provider.py test5_xmlprovider.py

# tests as of 4.0.7: 167 passed in 0.90s
# The suite files must run in this order and single-threaded because they
# share global topic-manager state.

.include <bsd.port.mk>
