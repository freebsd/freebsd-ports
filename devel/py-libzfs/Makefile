# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libzfs
PORTVERSION=	1.0.20171215
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python libzfs bindings

LICENSE=	BSD2CLAUSE

BROKEN_mips=		fails to build: libzfs.c: error: convert_for_assignment: incompatible type for argument 3 of zfs_path_to_zhandle
BROKEN_mips64=		fails to build: libzfs.c: error: convert_for_assignment: incompatible type for argument 3 of zfs_path_to_zhandle
BROKEN_powerpc64=	fails to build: libzfs.c: error: convert_for_assignment: incompatible type for argument 3 of zfs_path_to_zhandle

RUN_DEPENDS=	${PY_ENUM34}

USE_GITHUB=     yes
GH_ACCOUNT=	freenas
GH_PROJECT=	py-libzfs
GH_TAGNAME=	e0b4b68

USES=		python
USE_PYTHON=	autoplist distutils cython

MAKE_ENV=	FREEBSD_SRC=${SRC_BASE}

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

.include <bsd.port.mk>
