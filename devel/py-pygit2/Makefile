# Also update devel/libgit2, devel/libgit2-glib, devel/rubygem-rugged

PORTNAME=	pygit2
PORTVERSION=	1.18.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Python bindings for libgit2
WWW=		https://www.pygit2.org \
		https://github.com/libgit2/pygit2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.4.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libgit2.so.1.9:devel/libgit2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.4.0:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pygit2/_*git2*.so \

.include <bsd.port.mk>
