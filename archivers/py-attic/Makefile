# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	attic
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Attic-${PORTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	Deduplicating backup program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.1.10:devel/py-msgpack@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.1.10:devel/py-msgpack@${FLAVOR}

USES=		python:3.3+ ssl
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILDPATH=${BUILD_WRKSRC}/build/lib.${OPSYS:tl}-${UNAMER}-${ARCH}-${PYTHON_VER}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/attic/*.so

do-test:
	cd ${WRKDIR} && ${SETENV} PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${PYTHONPATH}" \
		${PYTHON_CMD} -m attic.testsuite.run

.include <bsd.port.mk>
