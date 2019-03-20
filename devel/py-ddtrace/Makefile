# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ddtrace
PORTVERSION=	0.23.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog tracing code

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentracing>=2.0.0:devel/py-opentracing@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@${REINPLACE_CMD} -e 's|msgpack-python|msgpack|' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ddtrace/vendor/wrapt/_wrappers.so

.include <bsd.port.mk>
