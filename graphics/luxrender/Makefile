# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	luxrender
DISTVERSION?=	1.5
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/luxrender/lux/get/ \
		https://bitbucket.org/luxrender/luxrays/get/:lr
DISTFILES=	v${DISTVERSION:C/[.-]//g}${EXTRACT_SUFX} \
		${PORTNAME}_v${DISTVERSION:S/-//}${EXTRACT_SUFX}:lr
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Physically based and unbiased rendering system

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfreeimage.so:${PORTSDIR}/graphics/freeimage \
		libOpenImageIO.so:${PORTSDIR}/graphics/openimageio
.if ${DISTVERSION} > 1.4
LIB_DEPENDS+=	libembree.so:${PORTSDIR}/graphics/embree
.endif

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses SSE instructions

USES=		bison cmake execinfo python:version tar:bzip2
USE_GL=		glut glew
WRKSRC=		${WRKDIR}/${PORTNAME}-lux-${LUX_REV}
LUXRAYS_WRKSRC=	${WRKDIR}/${PORTNAME}-luxrays-${LUXRAYS_REV}

CMAKE_ARGS=	-DLUXCORE_INCLUDE_DIRS:PATH="${LUXRAYS_WRKSRC}/include" \
		-DLUXCORE_LIBRARY:STRING="${LUXRAYS_WRKSRC}/lib/libluxcore.a" \
		-DLUXRAYS_INCLUDE_DIRS:PATH="${LUXRAYS_WRKSRC}/include" \
		-DLUXRAYS_LIBRARY:STRING="${LUXRAYS_WRKSRC}/lib/libluxrays.a" \
		-DSLG_INCLUDE_DIRS:PATH="${LUXRAYS_WRKSRC}/include" \
		-DSLG_LIBRARY:PATH="${LUXRAYS_WRKSRC}/lib/libsmallluxgpu.a" \
		-DLUXRAYS_DISABLE_OPENCL:BOOL=ON

LUX_REV?=	216e294b59e3
LUXRAYS_REV?=	3674460aa1da

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11

X11_DESC=	Build GUI executable (requires Qt 4)
X11_USE=	QT4=moc_build,qmake_build,rcc_build,uic_build,corelib,gui
X11_PLIST_FILES=	bin/luxrender

pre-patch:
	@${LN} -sf ${PORTNAME}-luxrays-${LUXRAYS_REV} ${WRKDIR}/luxrays

post-patch:
	@${REINPLACE_CMD} -e 's/__APPLE__/__FreeBSD__/' \
		${LUXRAYS_WRKSRC}/samples/smallluxgpu4/smallluxgpu.h \
		${WRKSRC}/core/osfunc.h \
		${WRKSRC}/shapes/mikktspace/weldmesh.c
# Avoid infamous "local symbol discarded in section `.text...' errors
	@${REINPLACE_CMD} -e '/^set(Boost_USE_STATIC_LIBS/s,ON,OFF,' \
		${LUXRAYS_WRKSRC}/cmake/Dependencies.cmake
# Avoid picking up Python 3.x bits if they're installed
	@${REINPLACE_CMD} -e 's,PythonLibs,& ${PYTHON_VER} EXACT REQUIRED,' \
		${LUXRAYS_WRKSRC}/cmake/Dependencies.cmake \
		${WRKSRC}/cmake/pylux.cmake

pre-configure:
	cd ${LUXRAYS_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
		${CMAKE_ARGS} .
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} -C ${LUXRAYS_WRKSRC}

.include <bsd.port.mk>
