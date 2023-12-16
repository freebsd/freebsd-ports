PORTNAME=	sdr-wspr
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	12
CATEGORIES=	comms hamradio

MAINTAINER=	jeff@baitis.net
COMMENT=	WSPR receiver/decoder using libsdr
WWW=		https://github.com/hmatuschek/sdr-wspr

LICENSE=	GPLv3

DEPRECATED=		Depends on deprecated www/qt5-webkit
EXPIRATION_DATE=	2023-12-31
BROKEN_FreeBSD_14=	fails to build: non-floating-point argument in call to function '__builtin_isfinite'

LIB_DEPENDS=	libsdr-gui.so:comms/libsdr-gui

USES=		cmake compiler:gcc-c++11-lib fortran pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	hmatuschek
USE_QT=		core buildtools:build qmake webkit widgets

PLIST_FILES=	bin/sdr-wspr share/applications/sdr-wspr.desktop \
		share/icons/sdr-wspr.svg
CMAKE_ARGS=	-DCMAKE_INSTALL_RPATH:STRING="${LOCALBASE}/lib/gcc${_GCC_VER}"

.include <bsd.port.mk>
