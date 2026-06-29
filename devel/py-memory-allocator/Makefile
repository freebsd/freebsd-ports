PORTNAME=	memory_allocator
PORTVERSION=	0.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Allocate memory easily with cython
WWW=		https://github.com/sagemath/memory_allocator

LICENSE=	GPLv3

USES=		meson pkgconfig python
USE_PYTHON=	cython
BINARY_ALIAS=	cython=cython-${PYTHON_VER}

.include <bsd.port.mk>
