PORTNAME=	${GH_PROJECT:tl}
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.1
CATEGORIES=	audio

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Free music composition & notation software
WWW=		https://musescore.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libasound.so:audio/alsa-lib \
		libasound_module_pcm_oss.so:audio/alsa-plugins \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lib localbase \
		pkgconfig qt:5
USE_QT=		concurrent core dbus declarative designer graphicaleffects gui \
		help location network networkauth opengl printsupport \
		quickcontrols quickcontrols2 scripttools sql svg testlib \
		webchannel widgets x11extras xml xmlpatterns \
		buildtools:build linguisttools:build qmake:build uitools:build

USE_GITHUB=	yes
GH_PROJECT=	MuseScore

# Each release gets a subdir containing the distfiles for that release,
# so hope that scanning the parent dir finds new ones.
#
# Note needs PORTVERSION:R once there is a .minor version
DATADIR=	${PREFIX}/share/mscore-${PORTVERSION:R}

CMAKE_OFF=	MUE_BUILD_CRASHPAD_CLIENT \
		MUE_COMPILE_USE_PCH
CMAKE_BUILD_TYPE=	release

post-stage:
	find ${STAGEDIR}${PREFIX}/lib -name '*.a' -delete # static libs from gtest
	find ${STAGEDIR}${PREFIX}/lib/cmake -name '*.cmake' -delete # cmake configuration for kddockwidget
	find ${STAGEDIR}${PREFIX}/include -name '*.h' -delete # headers for gtest, dockwidgets
	find ${STAGEDIR}${PREFIX}/include -name 'README.md' -delete # readmes from gtest
	find ${STAGEDIR}${PREFIX}/libdata -name '*.pc' -delete # pkgconfig from gtest
	rmdir \
		${STAGEDIR}${PREFIX}/include/gmock/internal/custom \
		${STAGEDIR}${PREFIX}/include/gmock/internal \
		${STAGEDIR}${PREFIX}/include/gmock \
		${STAGEDIR}${PREFIX}/include/gtest/internal/custom \
		${STAGEDIR}${PREFIX}/include/gtest/internal \
		${STAGEDIR}${PREFIX}/include/gtest \
		${STAGEDIR}${PREFIX}/include/kddockwidgets/private/indicators \
		${STAGEDIR}${PREFIX}/include/kddockwidgets/private/multisplitter \
		${STAGEDIR}${PREFIX}/include/kddockwidgets/private/quick \
		${STAGEDIR}${PREFIX}/include/kddockwidgets/private \
		${STAGEDIR}${PREFIX}/include/kddockwidgets \
		${STAGEDIR}${PREFIX}/include/opus \
		${STAGEDIR}${PREFIX}/lib/cmake/GTest \
		${STAGEDIR}${PREFIX}/lib/cmake/KDDockWidgets \
		${STAGEDIR}${PREFIX}/lib/cmake

.include <bsd.port.mk>
