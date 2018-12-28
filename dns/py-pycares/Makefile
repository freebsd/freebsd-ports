# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	pycares
PORTVERSION=	2.3.0
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python interface to c-ares

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist concurrent

PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS=		--inplace --force

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_core.so

do-test:
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} tests/tests.py

.include <bsd.port.mk>
