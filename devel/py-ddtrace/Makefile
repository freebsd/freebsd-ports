PORTNAME=	ddtrace
PORTVERSION=	2.9.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/abseil/abseil-cpp/releases/download/20240116.2/:abseil
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	ddtrace-${PORTVERSION}${EXTRACT_SUFX} \
		abseil-cpp-20240116.2${EXTRACT_SUFX}:abseil

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog APM client library
WWW=		https://ddtrace.readthedocs.io/en/stable/ \
		https://github.com/DataDog/dd-trace-py

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libddwaf.so:devel/libddwaf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=20:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bytecode>=0.15.0:devel/py-bytecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cattrs>=0:devel/py-cattrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ddsketch>=3.0.0:devel/py-ddsketch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}envier>=0.5<1:devel/py-envier@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.12:devel/py-xmltodict@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++17-lang python shebangfix
USE_PYTHON=	autoplist concurrent cython pep517

PORTSCOUT=	limit:^[0-9]*\.[0-9]*\.[0-9]*

SHEBANG_FILES=	ddtrace/internal/datadog/profiling/cmake/tools/fetch_infer.sh \
		ddtrace/internal/datadog/profiling/cmake/tools/fetch_libdatadog.sh \
		ddtrace/internal/datadog/profiling/setup_custom.sh

OPTIONS_DEFINE=	OPENTRACING
OPTIONS_DEFAULT=OPENTRACING
OPENTRACING_DESC=	OpenTracing support

OPENTRACING_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}opentracing>=2.0.0:devel/py-opentracing@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
.endif

post-patch:
	${MV} ${WRKDIR}/abseil-cpp-20240116.2/ ${WRKSRC}/ddtrace/appsec/_iast/_taint_tracking/_deps/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
