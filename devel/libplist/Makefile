# $FreeBSD$

PORTNAME=	libplist
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Library to handle Apple Property List format

LICENSE=	LGPL21

USE_GNOME=	libxml2
# Unlisted dependency.
USE_ICONV=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
# Required for iconv headers.
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	${LOCALBASE}/lib

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	CYTHON SWIG

CYTHON_DESC=	Cython Python bindings
SWIG_DESC=	Swig Python bindings

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCYTHON}
BUILD_DEPENDS+=	cython:${PORTSDIR}/lang/cython
USE_PYTHON=	yes
CMAKE_ARGS+=	-DENABLE_CYTHON:BOOL=On
PLIST_SUB+=	CYTHON=""
.else
CMAKE_ARGS+=	-DENABLE_CYTHON:BOOL=Off
PLIST_SUB+=	CYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MSWIG}
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
