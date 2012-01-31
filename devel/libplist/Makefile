# New ports collection makefile for:	libplist
# Date created:				28 May 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libplist
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	A library to handle Apple Property List format

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USE_GNOME=	libxml2
# Unlisted dependency.
USE_ICONV=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
# Required for iconv headers.
CFLAGS+=	-I${LOCALBASE}/include
# Required for MAKE_JOBS_SAFE to work.
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	${LOCALBASE}/lib

PORTDOCS=	AUTHORS NEWS README

OPTIONS=	CYTHON	"Enable Cython Python bindings" off \
		SWIG	"Enable Swig Python bindings" off

.include <bsd.port.options.mk>

.ifdef(WITH_CYTHON)
BUILD_DEPENDS+=	cython:${PORTSDIR}/lang/cython
USE_PYTHON=	yes
CMAKE_ARGS+=	-DENABLE_CYTHON:BOOL=On
# Is this really needed?
USE_LDCONFIG+=	${PYTHON_SITELIBDIR}
PLIST_SUB+=	CYTHON=""
.else
CMAKE_ARGS+=	-DENABLE_CYTHON:BOOL=Off
PLIST_SUB+=	CYTHON="@comment "
.endif

.ifdef(WITH_SWIG)
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
USE_PYTHON=	yes
CMAKE_ARGS+=	-DENABLE_SWIG:BOOL=On
PLIST_SUB+=	SWIG=""
.else
CMAKE_ARGS+=	-DENABLE_SWIG:BOOL=Off
PLIST_SUB+=	SWIG="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's:$${CMAKE_INSTALL_LIBDIR}/pkgconfig:libdata/pkgconfig:' \
		${WRKSRC}/CMakeLists.txt

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
