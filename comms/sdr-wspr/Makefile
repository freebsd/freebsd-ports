# Created by: Jeffrey Baitis <jeff@baitis.net>
# $FreeBSD$

PORTNAME=	sdr-wspr
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	10
CATEGORIES=	comms hamradio

MAINTAINER=	jeff@baitis.net
COMMENT=	WSPR receiver/decoder using libsdr

LICENSE=	GPLv3

LIB_DEPENDS=	libsdr-gui.so:comms/libsdr-gui

USES=		cmake compiler:gcc-c++11-lib fortran pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	hmatuschek
USE_QT=		core buildtools_build qmake webkit widgets

PLIST_FILES=	bin/sdr-wspr share/applications/sdr-wspr.desktop \
		share/icons/sdr-wspr.svg
CMAKE_ARGS=	-DCMAKE_INSTALL_RPATH:STRING="${LOCALBASE}/lib/gcc${_GCC_VER}"

.include <bsd.port.mk>
