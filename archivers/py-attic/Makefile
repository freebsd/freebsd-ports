# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	attic
PORTVERSION=	0.16
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Attic-${PORTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	Deduplicating backup program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.1.10:devel/py-msgpack-python
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.1.10:devel/py-msgpack-python

USES=		python:3.3+
USE_PYTHON=	autoplist distutils
USE_OPENSSL=	yes

STRIP_FILES=	hashindex.so platform_freebsd.so chunker.so crypto.so
PYDISTUTILS_BUILDPATH=${BUILD_WRKSRC}/build/lib.${OPSYS:tl}-${UNAMER}-${ARCH}-${PYTHON_VER}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000015
BUILD_DEPENDS+=	openssl>=1.0:security/openssl
RUN_DEPENDS+=	openssl>=1.0:security/openssl
.endif

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

regression-test: build
	${SETENV} PYTHONPATH="${PYDISTUTILS_BUILDPATH}:${PYTHONPATH}" \
	  ${PYTHON_CMD} -m attic.testsuite.run

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/attic/,}

.include <bsd.port.post.mk>
