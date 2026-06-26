PORTNAME=	ddtrace
PORTVERSION=	4.10.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	ddtrace-${PORTVERSION}${EXTRACT_SUFX}

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
LIB_DEPENDS=	libdatadog_profiling_ffi.so:devel/libdatadog \
		libddwaf.so:devel/libddwaf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bytecode>=0.17.0<1:devel/py-bytecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}envier>=0.6.1<0.7:devel/py-envier@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1<3:devel/py-wrapt@${PY_FLAVOR}

USES=		cargo cmake:indirect compiler:c++17-lang python shebangfix
USE_PYTHON=	autoplist concurrent cython pep517

CARGO_BUILD=	no
CARGO_CARGOLOCK=${WRKSRC}/src/native/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/src/native/Cargo.toml
CARGO_INSTALL=	no
MAKE_ENV=	CIBUILDWHEEL=1 \
		DD_COMPILE_ABSEIL=0 \
		DD_COMPILE_MODE=Release \
		DD_PROFILING_NATIVE_TESTS=0 \
		DD_SETUP_FORCE_CYTHONIZE=1

PORTSCOUT=	limit:^[0-9]*\.[0-9]*\.[0-9]*

SHEBANG_GLOB=	*.sh

OPTIONS_DEFINE=	OPENTELEMETRY OPENTRACING
OPTIONS_DEFAULT=OPENTELEMETRY OPENTRACING
OPENTELEMETRY_DESC=	OpenTelemetry support
OPENTRACING_DESC=	OpenTracing support

OPENTELEMETRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp>=1<2:devel/py-opentelemetry-exporter-otlp@${PY_FLAVOR}
OPENTRACING_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}opentracing>=2<3:devel/py-opentracing@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py ${WRKSRC}/../libdatadog-37d17ee71ae396782242d45e1b31af2887bbbbd3/libdd-library-config/src/lib.rs

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
