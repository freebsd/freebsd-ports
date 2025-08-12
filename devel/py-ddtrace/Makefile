PORTNAME=	ddtrace
PORTVERSION=	2.21.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/abseil/abseil-cpp/releases/download/${ABSEIL_VERSION}/:abseil
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	ddtrace-${PORTVERSION}${EXTRACT_SUFX} \
		abseil-cpp-${ABSEIL_VERSION}${EXTRACT_SUFX}:abseil

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog APM client library
WWW=		https://ddtrace.readthedocs.io/en/stable/ \
		https://github.com/DataDog/dd-trace-py

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>=0<2:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libddwaf.so:devel/libddwaf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bytecode>=0.16.0:devel/py-bytecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}envier>=0.5<1:devel/py-envier@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1:devel/py-wrapt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.12:devel/py-xmltodict@${PY_FLAVOR}

USES=		cargo cmake:indirect compiler:c++17-lang python shebangfix
USE_PYTHON=	autoplist concurrent cython pep517

CARGO_BUILD=	no
CARGO_CARGOLOCK=${WRKSRC}/src/core/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/src/core/Cargo.toml
CARGO_INSTALL=	no

ABSEIL_VERSION=	20250127.1

PORTSCOUT=	limit:^[0-9]*\.[0-9]*\.[0-9]*

SHEBANG_GLOB=	*.sh

OPTIONS_DEFINE=	OPENAI OPENTRACING
OPTIONS_DEFAULT=OPENAI OPENTRACING
OPENAI_DESC=		Calculate number of tokens
OPENTRACING_DESC=	OpenTracing support

OPENAI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tiktoken>=0:textproc/py-tiktoken@${PY_FLAVOR}
OPENTRACING_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}opentracing>=2.0.0:devel/py-opentracing@${PY_FLAVOR}

post-patch:
	@${MV} ${WRKDIR}/abseil-cpp-${ABSEIL_VERSION}/ ${WRKSRC}/ddtrace/appsec/_iast/_taint_tracking/absl/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
