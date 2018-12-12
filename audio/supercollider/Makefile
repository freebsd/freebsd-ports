# $FreeBSD$

PORTNAME=	supercollider
DISTVERSION=	3.9.3
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	https://github.com/supercollider/supercollider/releases/download/Version-${PORTVERSION}/
DISTNAME=	SuperCollider-${PORTVERSION}-Source-linux

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Programming language for real time audio synthesis

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/intrusive/unordered_set.hpp:devel/boost-libs
LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libavahi-common.so:net/avahi-app \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		libfftw3f.so:math/fftw3-float

USES=		cmake:outsource compiler:c++11-lang iconv localbase pkgconfig \
		qt:5 readline shared-mime-info tar:bzip2
USE_QT=		buildtools_build concurrent core declarative gui linguisttools location \
		network opengl printsupport qmake_build sensors \
		sql webkit widgets
USE_XORG=	x11
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/SuperCollider-Source

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib/qt5 \
		-DLIBUSB_1_INCLUDE_DIR=/usr/include \
		-DLIBUSB_1_LIBRARY=/usr/lib/libusb.so \
		-DLIBSCSYNTH=ON

DESKTOP_ENTRIES="SuperCollider IDE" "" "${LOCALBASE}/share/pixmaps/sc_ide.svg" \
		"scide" "" false

OPTIONS_DEFINE=		HELP SUPERNOVA
OPTIONS_DEFAULT=	HELP SUPERNOVA
OPTIONS_SUB=	yes

HELP_DESC=	Install on-line help text
SUPERNOVA_DESC=	Build with supernova as optional audio synthesis server

HELP_CMAKE_BOOL=	INSTALL_HELP
SUPERNOVA_CMAKE_BOOL=	SUPERNOVA

.include <bsd.port.pre.mk>

.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
CMAKE_ARGS+=	-DSSE:BOOL=FALSE -DSSE2:BOOL=FALSE
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MATCHES "Linux" AND|MATCHES "FreeBSD" AND|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|if(DL)|if(TRUE)|; s|target_link_libraries(libsupernova $${DL})|#|' \
		${WRKSRC}/server/supernova/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|CMAKE_SYSTEM_NAME MATCHES "Linux"|CMAKE_SYSTEM_NAME MATCHES "FreeBSD"|' \
		${WRKSRC}/server/plugins/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|__linux__|__FreeBSD__|' ${WRKSRC}/server/supernova/server/main.cpp

.include <bsd.port.post.mk>
