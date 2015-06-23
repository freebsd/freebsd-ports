# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libzfs
PORTVERSION=	1.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python libzfs bindings

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	cython>0:${PORTSDIR}/lang/cython

USE_GITHUB=     yes
GH_ACCOUNT=	freenas
GH_PROJECT=	py-libzfs
GH_TAGNAME=	af5d66e

USES=		python
USE_PYTHON=	autoplist distutils

MAKE_ENV=	FREEBSD_SRC=${SRC_BASE}

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} <= 1000000
IGNORE=	This module requires at least FreeBSD 10
.endif

.include <bsd.port.post.mk>
