# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ddtrace
PORTVERSION=	0.49.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog tracing code

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=4:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=3,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=5:devel/py-tenacity@${PY_FLAVOR}

USES=		compiler:c11 python:3.6+
USE_PYTHON=	autoplist concurrent cython distutils

OPTIONS_DEFINE=	OPENTRACING
OPTIONS_DEFAULT=OPENTRACING
OPENTRACING_DESC=	OpenTracing support

OPENTRACING_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}opentracing>=2.0.0:devel/py-opentracing@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pep562>=0:devel/py-pep562@${PY_FLAVOR}
.endif

post-patch:
	@${RM} ${WRKSRC}/ddtrace/profiling/collector/stack.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ddtrace/vendor/*/*.so

.include <bsd.port.post.mk>
