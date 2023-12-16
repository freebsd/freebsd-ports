# Also update devel/libgit2, devel/libgit2-glib, devel/rubygem-rugged

PORTNAME=	pygit2
PORTVERSION=	1.13.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Python bindings for libgit2
WWW=		https://www.pygit2.org \
		https://github.com/libgit2/pygit2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.4.0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libgit2.so:devel/libgit2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.4.0:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
MAKE_ENV=	LIBGIT2=${LOCALBASE}
PYDISTUTILS_TEST_TARGET?=	test

do-test:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_TEST_TARGET} ${PYDISTUTILS_TESTARGS})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pygit2/_*git2*.so \

.include <bsd.port.mk>
