PORTNAME=	libzfs
DISTVERSIONPREFIX=v
DISTVERSION=	2.0.1
CATEGORIES=	filesystems devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Python libzfs bindings
WWW=		https://github.com/asomers/py-libzfs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

HAS_CONFIGURE=	yes
USES=		compiler:c11 python
USE_PYTHON=	autoplist cython distutils

USE_GITHUB=	yes
GH_ACCOUNT=	asomers
GH_PROJECT=	py-libzfs

CONFIGURE_ENV=	freebsd_src=${SRC_BASE}
MAKE_ENV=	freebsd_src=${SRC_BASE}

.include <bsd.port.options.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files in ${SRC_BASE}
.endif

.include <bsd.port.mk>
