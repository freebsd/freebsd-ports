# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	luxrender
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://src.luxrender.net/lux/get/ \
		http://src.luxrender.net/luxrays/get/:lr
DISTFILES=	v${PORTVERSION:S/.//g}${EXTRACT_SUFX} \
		luxrender_v${PORTVERSION}${EXTRACT_SUFX}:lr
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Physically based and unbiased rendering system

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfreeimage.so:${PORTSDIR}/graphics/freeimage \
		libpng15.so:${PORTSDIR}/graphics/png \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
.if !exists(/usr/include/execinfo.h)
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses SSE extensions

USES=		bison cmake tar:bzip2
USE_GL=		glut glew
WRKSRC=		${WRKDIR}/luxrender-lux-${LUX_REV}
LUXRAYS_WRKSRC=	${WRKDIR}/luxrender-luxrays-${LUXRAYS_REV}

CMAKE_ARGS=	-DLUXRAYS_INCLUDE_DIRS:PATH="${LUXRAYS_WRKSRC}/include" \
		-DLUXRAYS_LIBRARY:STRING="${LUXRAYS_WRKSRC}/lib/libluxrays.a" \
		-DSLG_INCLUDE_DIRS:PATH="${LUXRAYS_WRKSRC}/include" \
		-DSLG_LIBRARY:PATH="${LUXRAYS_WRKSRC}/lib/libsmallluxgpu.a" \
		-DLUXRAYS_DISABLE_OPENCL:BOOL=ON

LUX_REV=	d0b0e20c47cc
LUXRAYS_REV=	7459cd8a9583

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11

X11_DESC=	Build GUI executable (Qt4-based)
X11_USE=	QT4=moc_build,qmake_build,rcc_build,uic_build,corelib,gui
X11_PLIST_FILES=	bin/luxrender

post-patch:
	@${REINPLACE_CMD} -e 's/__APPLE__/__FreeBSD__/' \
		${LUXRAYS_WRKSRC}/samples/smallluxgpu4/smallluxgpu.h \
		${WRKSRC}/core/osfunc.h \
		${WRKSRC}/shapes/mikktspace/weldmesh.c
	@${REINPLACE_CMD} -e '/^set(Boost_USE_STATIC_LIBS/s,ON,OFF,' \
		${LUXRAYS_WRKSRC}/cmake/Dependencies.cmake

pre-configure:
	cd ${LUXRAYS_WRKSRC} && ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} \
		${CMAKE_ARGS} .
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} -C ${LUXRAYS_WRKSRC}

.include <bsd.port.mk>
