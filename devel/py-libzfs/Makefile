#
# $FreeBSD$
# $Id$
#

PORTNAME=      	libzfs
PORTVERSION=	1.0
PORTREVISION=	1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

CATEGORIES=	devel

MAINTAINER=     dev@ixsystems.com
COMMENT=        Python libzfs bindings

USES=		python
USE_PYTHON=	autoplist distutils
EXTRACT_ONLY=
BUILD_DEPENDS=  ${LOCALBASE}/bin/cython:lang/cython

WRKSRC?=/usr/nas_source/py-libzfs

MAKE_ENV=       FREEBSD_SRC=/usr/src TRUEOS=yes

checksum fetch:
	echo ${.TARGET} not needed because building direct

.include <bsd.port.mk>
