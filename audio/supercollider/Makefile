# $FreeBSD$

PORTNAME=	supercollider
PORTVERSION=	3.8.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/supercollider/supercollider/releases/download/Version-${PORTVERSION}/
DISTNAME=	SuperCollider-${PORTVERSION}-Source-linux

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Programming language for real time audio synthesis

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libavahi-common.so:net/avahi-app \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile

DESKTOP_ENTRIES="SuperCollider IDE" "" "${LOCALBASE}/share/pixmaps/sc_ide.svg" \
		"scide" "" ${FALSE}

USES=	cmake:outsource iconv localbase pkgconfig readline shared-mime-info \
	tar:bzip2
USE_QT5=	buildtools_build concurrent core gui linguisttools location \
		network opengl printsupport qmake_build qml quick sensors \
		sql webkit widgets
USE_XORG=	xt

WRKSRC=	${WRKDIR}/SuperCollider-Source

CMAKE_ENV=	PKG_CONFIG_PATH=${LOCALBASE}/libdata/pkgconfig
CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib/qt5 \
		-DLIBUSB_1_INCLUDE_DIR=/usr/include \
		-DLIBUSB_1_LIBRARY=/usr/lib/libusb.so

.include <bsd.port.mk>
