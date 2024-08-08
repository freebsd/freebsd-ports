PORTNAME=	dm-tree
DISTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for working with nested data structures
WWW=		https://tree.readthedocs.io/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libabsl_strings.so:devel/abseil

USES=		localbase python
USE_PYTHON=	distutils concurrent

MAKE_ENV=	FREEBSD_LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
