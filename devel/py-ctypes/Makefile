# New ports collection makefile for:	py-ctypes
# Date created:		12 May 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ctypes
PORTVERSION=	0.9.6
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%/,ctypes/,g}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python module allowing to create and manipulate C data types

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

ONLY_FOR_ARCHS=	i386 alpha powerpc

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} \
		-e 's|\(Extension(.*\)$$|\1 define_macros=[("ffi_type_schar", \
		"ffi_type_sint8"), ("ffi_type_sshort","ffi_type_sint16")],|' \
		-e 's|define_macros=\[.*CAN_PASS_BY_VALUE.*\],||' \
		${WRKSRC}/setup.py

.include <bsd.port.post.mk>
