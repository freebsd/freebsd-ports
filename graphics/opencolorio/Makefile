# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	opencolorio
PORTVERSION=	1.0.7
CATEGORIES=	graphics multimedia
MASTER_SITES=	https://github.com/imageworks/OpenColorIO/tarball/
DISTNAME=	v${PORTVERSION}
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Complete color management solution

LICENSE=	BSD

LIB_DEPENDS=	OpenImageIO:${PORTSDIR}/graphics/openimageio

FETCH_ARGS=	-pRr
USE_CMAKE=	yes
CMAKE_VERBOSE=	yes
CMAKE_OUTSOURCE=	yes
CMAKE_ARGS=	-DOCIO_BUILD_JNIGLUE:BOOL=OFF \
		-DOCIO_BUILD_PYGLUE:BOOL=OFF
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/imageworks-OpenColorIO-b3cb224
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=		CLIAPPS SSE
OPTIONS_DEFAULT=	SSE

CLIAPPS_DESC=	Build cli apps
SSE_DESC=	Enable sse optimizations

.include <bsd.port.options.mk>

.if ${CC:T} != "clang"
USE_GCC=	4.6+
.endif

.if empty(PORT_OPTIONS:MDOCS)
CMAKE_ARGS+=	-DOCIO_BUILD_DOCS:BOOL=OFF
.else
# docs currently broken
CMAKE_ARGS+=	-DOCIO_BUILD_DOCS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MCLIAPPS}
.if ${CC:T} != "clang"
BROKEN=		cli apps don't build with gcc
.endif
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=ON
PLIST_SUB+=	CLIAPPS=""
.else
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF
PLIST_SUB+=	CLIAPPS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${OSVERSION} < 803000
# this is needed for linking with openimageio
LDFLAGS+=	-L${LOCALBASE}/lib/gcc46 -rpath ${LOCALBASE}/lib/gcc46
.endif

.if ${CC:T} == "clang" && ${ARCH} == "i386"
# workaround for pr/165968
# may need to test osversion after fix is applied
CFLAGS+=	-march=pentium2
.endif

.if ${PORT_OPTIONS:MSSE}
CMAKE_ARGS+=	-DOCIO_USE_SSE:BOOL=ON
.else
CMAKE_ARGS+=	-DOCIO_USE_SSE:BOOL=OFF
.endif

.include <bsd.port.post.mk>
