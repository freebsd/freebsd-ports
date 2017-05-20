# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libzfs
PORTVERSION=	1.0.20170319
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python libzfs bindings

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	fails to build: libzfs.c: error: convert_for_assignment: incompatible type for argument 3 of zfs_path_to_zhandle

USE_GITHUB=     yes
GH_ACCOUNT=	freenas
GH_PROJECT=	py-libzfs
GH_TAGNAME=	fb5b8f2

USES?=		python
USE_PYTHON=	autoplist distutils

MAKE_ENV=	FREEBSD_SRC=${SRC_BASE}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3306
BUILD_DEPENDS=	cython3>0:lang/cython3
.else
BUILD_DEPENDS=	cython>0:lang/cython
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

.include <bsd.port.post.mk>
