# New ports collection makefile for:	py-ctypes
# Date created:		12 May 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ctypes
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%/,ctypes/:pyctypes,g} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%/,perky/:libffi,g}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	ctypes-${PORTVERSION}.tar.gz:pyctypes \
		libffi-${LIBFFIVERSION}.tar.gz:libffi

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python module allowing to create and manipulate C data types

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

# libffi on ports is incompatible with this port. so, we link the recent
# version of it static.
LIBFFIVERSION=	030511
LIBFFIWRKSRC=	${WRKDIR}/libffi-${LIBFFIVERSION}
CONFIGURE_ARGS=	--enable-static --disable-shared
CONFIGURE_WRKSRC=${LIBFFIWRKSRC}

ONLY_FOR_ARCHS=	i386 alpha powerpc

.include <bsd.port.pre.mk>

post-patch:
	${LN} -sf ${LIBFFIWRKSRC}/config-ml.in ${LIBFFIWRKSRC}/..
	${REINPLACE_CMD} -e 's|\(include_dirs = \).*|\1["${LIBFFIWRKSRC}/include"]|' \
		-e 's|\(libraries=\["ffi"\]\)|\1,library_dirs=["${LIBFFIWRKSRC}/.libs"]|' \
		-e 's|\(Extension(.*\)$$|\1 define_macros=[("ffi_type_schar", \
		"ffi_type_sint8"), ("ffi_type_sshort","ffi_type_sint16")],|' \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} -e 's,\(alpha\*-.*-osf.*\)),\1 | alpha*-*-freebsd*),' \
		${LIBFFIWRKSRC}/configure
.if ${ARCH} == "ia64"
	${LN} -sf ${LIBFFIWRKSRC}/${ARCH}/${ARCH}_flags.h ${LIBFFIWRKSRC}/
	${REINPLACE_CMD} -e 's|defined(IA64)|defined(__ia64__)|' \
		${LIBFFIWRKSRC}/include/ffi.h
.endif

pre-build:
	cd ${LIBFFIWRKSRC}; ${MAKE_ENV} ${GMAKE}

.include <bsd.port.post.mk>
