# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mitsuba
PORTVERSION=	0.5.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	https://www.mitsuba-renderer.org/repos/mitsuba/archive/${HG_REVISION}${EXTRACT_SUFX}?dummy=
DISTNAME=	${PORTNAME}-${HG_REVISION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Research-oriented physically based rendering system

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpng.so:graphics/png \
		libIlmImf.so:graphics/OpenEXR \
		libxerces-c.so:textproc/xerces-c3 \
		libfftw3.so:math/fftw3

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses SSE instructions

USES=		cmake jpeg tar:bzip2
USE_GL=		glew
USE_QT4=	moc_build qmake_build rcc_build uic_build \
		gui opengl network xml xmlpatterns

CMAKE_ARGS=	-DMTS_SIMPLE_PATHS:BOOL=OFF -DBUILD_PYTHON:BOOL=OFF \
		-DMTS_USE_PCH:BOOL=OFF

# Parallel build does not work as expected: it remains single-thread while
# deferring build process to the background and also inhibiting highlights
# from Clang output; these bugs should be fixed before enabling -jX builds.
MAKE_JOBS_UNSAFE=	yes

HG_REVISION=	11ee1d7236f3
FETCH_ARGS=	-o ${DISTNAME}${EXTRACT_SUFX}

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_SYSTEM_NAME/s,Linux,${OPSYS},' \
		${WRKSRC}/data/cmake/MitsubaExternal.cmake \
		${WRKSRC}/data/cmake/PCHTargets.cmake \
		${WRKSRC}/src/libcore/CMakeLists.txt \
		${WRKSRC}/src/libhw/CMakeLists.txt

post-install:
# XXX: palliative; better fix installation routine not to pollute ${STAGEDIR}
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/mitsuba/data/ior/CMakeFiles

.include <bsd.port.mk>
