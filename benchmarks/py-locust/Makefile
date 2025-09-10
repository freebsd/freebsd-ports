PORTNAME=	locust
DISTVERSION=	2.37.10
PORTREVISION=	1
CATEGORIES=	benchmarks www python
MASTER_SITES=	PYPI \
		https://github.com/locustio/locust/archive/refs/tags/:EXTRA
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTVERSION}${EXTRACT_SUFX}:EXTRA
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Python utility for doing easy, distributed load testing
WWW=		https://locust.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=0:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>=0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Login>=0:www/py-flask-login@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geventhttpclient>=0:devel/py-geventhttpclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}locust-cloud>=0:benchmarks/py-locust-cloud@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyquery>=0:devel/py-pyquery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retry2>=0:devel/py-retry2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	cryptography_test pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

EXTRA_DIRNAME=	${PORTNAME}-${PORTVERSION}-extra

post-extract:
	@${MKDIR} ${WRKDIR}/${EXTRA_DIRNAME}
	@${TAR} --strip-components=1 -xf ${_DISTDIR}/${PORTVERSION}${EXTRACT_SUFX} -C ${WRKDIR}/${EXTRA_DIRNAME}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${EXTRA_DIRNAME}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

do-test:
	@cd ${WRKDIR}/${EXTRA_DIRNAME}/locust/test && ${COPYTREE_SHARE} \
		. ${WRKSRC}/locust/test
	@cd ${WRKSRC}/locust/test && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		-v -rs -o addopts=

.include <bsd.port.mk>
