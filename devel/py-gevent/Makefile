PORTNAME=	gevent
PORTVERSION=	25.5.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python co-routine networking library based on greenlet
WWW=		https://www.gevent.org/ \
		https://python-gevent.readthedocs.io/ \
		https://github.com/gevent/gevent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	c-ares>=1.15.0:dns/c-ares \
		libev>=4.31:devel/libev \
		libuv>=1.34.0:devel/libuv \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.17.1:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=3.2.2:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libcares.so:dns/c-ares \
		libev.so:devel/libev \
		libuv.so:devel/libuv
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.17.1:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=3.2.2:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		compiler:c11 localbase python
USE_PYTHON=	autoplist concurrent cython3 pep517

MAKE_ENV=	GEVENTSETUP_EMBED_CARES=0 GEVENTSETUP_EMBED_LIBEV=0 GEVENTSETUP_EMBED_LIBUV=0
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

# Clean up bundled libraries
.if !defined(MAINTAINER_MODE)
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/deps \
			--no-same-owner --no-same-permissions
.else
post-patch:
	@${RM} -r ${WRKSRC}/deps/
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m gevent.tests

.include <bsd.port.mk>
