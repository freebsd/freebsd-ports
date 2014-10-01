# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygit2
PORTVERSION=	0.21.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python bindings for libgit2

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:${PORTSDIR}/devel/py-cffi
LIB_DEPENDS=	libgit2.so.0.${PORTVERSION:R:E}.0:${PORTSDIR}/devel/libgit2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils
MAKE_ENV=	LIBGIT2=${LOCALBASE}

.include <bsd.port.mk>
