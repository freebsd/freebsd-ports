# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygit2
PORTVERSION=	0.24.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python bindings for libgit2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi
LIB_DEPENDS=	libgit2.so:devel/libgit2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils
MAKE_ENV=	LIBGIT2=${LOCALBASE}

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pygit2.so ${STAGEDIR}${PYTHON_SITELIBDIR}/pygit2/_libgit2.so

.include <bsd.port.mk>
