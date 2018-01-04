# $FreeBSD$

PORTNAME=	xptools
DISTVERSION=	wed_161r1
CATEGORIES=	games

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	X-Plane Scenery Tools

LICENSE=	MIT

# Platform-specific defines in patch-src_XESCore_Airports.cpp.
# Somewhere on FlightGear wiki it is said WED would only work for AMD64 anyway.
ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	gnustat:sysutils/coreutils \
		${LOCALBASE}/lib/libntl.a:math/ntl \
		cmake:devel/cmake
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libjasper.so:graphics/jasper \
		libgeotiff.so:graphics/libgeotiff \
		libproj.so:graphics/proj \
		libmpfr.so:math/mpfr \
		libpng.so:graphics/png \
		libshp.so:devel/shapelib \
		libsquish.so:graphics/squish \
		libtiff.so:graphics/tiff \
		lib3ds.so:graphics/lib3ds \
		libGLw.so:graphics/libGLw \
		libGLU.so:graphics/libGLU

USES=		eigen:3 gmake jpeg sqlite ssl

USE_GITHUB=	yes
GH_ACCOUNT=	X-Plane
GH_SUBDIR=	libs:xptools_libs
GH_TAGNAME=	982173e:xptools_libs

USE_CXXSTD=	c++11
USE_BINUTILS=	yes
USE_QT4=	corelib gui moc opengl
USE_GL+=	gl

BINARIES=	DDSTool DSFTool MeshTool ObjConverter ObjView RenderFarm RenderFarmUI WED XGrinder XPlaneSupportLin.p

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
IGNORE=	the Makefile has no flags for both debug and optimization
.else
ALL_TARGET=		debug
.endif
.else
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
ALL_TARGET=		release-opt
.else
ALL_TARGET=		release
.endif
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e's:g++:${CXX}:g' \
		-e's|gcc|${CC}|g' \
		${WRKSRC}/makerules/global/toplevel.mk \
		${WRKSRC}/src/OneOffs/Makefile
	@${REINPLACE_CMD} \
		-e's:-Wl,--exclude-libs,libpng.a::g' \
		-e's:\./libs/local$$(MULTI_SUFFIX)/lib/libCGAL.a:XYZZY&:g' \
		-e's: \./libs/local$$(MULTI_SUFFIX)/lib/libCGAL_Core.a::g' \
		-e's:\./libs/local$$(MULTI_SUFFIX)/lib/libdime.a:XYZZY&:g' \
		-e's: .*libz.a: /usr/lib/libz.a /usr/lib/libbz2.a /usr/lib/liblzma.a:g' \
		-e's: \./libs/local$$(MULTI_SUFFIX)/lib: ${PREFIX}/lib:g' \
		-e's: ${PREFIX}/lib/libtiff.a:& ${PREFIX}/lib/libjbig.a:g' \
		-e's:XYZZY::g' \
		-e's: -ldl: -lexecinfo -lelf:g' \
		${WRKSRC}/makerules/ac3d \
		${WRKSRC}/makerules/DDSTool \
		${WRKSRC}/makerules/DSFTool \
		${WRKSRC}/makerules/ObjConverter \
		${WRKSRC}/makerules/ObjView \
		${WRKSRC}/makerules/RenderFarm \
		${WRKSRC}/makerules/WED \
		${WRKSRC}/makerules/XGrinder

pre-build:
	cd ${WRKSRC}/libs && ${GMAKE}

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/build/*/*/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
