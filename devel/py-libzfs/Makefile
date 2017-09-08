#
# $FreeBSD$
# $Id$
#

PORTNAME=      	libzfs
PORTVERSION=	1.0
PORTREVISION=	2
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

CATEGORIES=	devel

MAINTAINER=     dev@ixsystems.com
COMMENT=        Python libzfs bindings

USES?=		python
USE_PYTHON=	autoplist distutils
EXTRACT_ONLY=

WRKSRC?=/usr/nas_source/py-libzfs

MAKE_ENV=       FREEBSD_SRC=/usr/src TRUEOS=yes EXPERIMENTAL=yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3306
BUILD_DEPENDS=  cython3>0:lang/cython3
.else
BUILD_DEPENDS=  cython>0:lang/cython
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=   ${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

checksum fetch:
	echo ${.TARGET} not needed because building direct

.include <bsd.port.post.mk>
