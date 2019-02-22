# $FreeBSD$

PORTNAME=	cassandra-driver
DISTVERSION=	3.17.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sergey@akhmatov.ru
COMMENT=	Python client library for Apache Cassandra

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PY_FUTURES}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sure>0:devel/py-sure@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython distutils

OPTIONS_DEFINE=	LIBEV MURMUR3
LIBEV_DESC=	Use devel/libev for event loop
MURMUR3_DESC=	Enable murmur3 extension
OPTIONS_DEFAULT=	LIBEV MURMUR3

LIBEV_LIB_DEPENDS=	libev.so:devel/libev
LIBEV_VARS=	STRIPFILES=${STAGEDIR}${PYTHON_SITELIBDIR}/cassandra/io/libevwrapper.so
LIBEV_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--no-libev PYDISTUTILS_INSTALLARGS+=--no-libev

MURMUR3_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--no-murmur3 PYDISTUTILS_INSTALLARGS+=--no-murmur3

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' | ${XARGS} ${STRIP_CMD}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
