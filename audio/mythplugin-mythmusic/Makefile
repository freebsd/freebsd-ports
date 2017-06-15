# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythmusic
PORTVERSION=	0.27.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMEPREFIX=	mythplugin-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music playing plugin for MythTV

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis \
		libtag.so:audio/taglib \
		libfftw3f.so:math/fftw3-float
BUILD_DEPENDS=	mythfrontend:multimedia/mythtv

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_PROJECT=	mythtv

WRKSRC_SUBDIR=	mythplugins

USE_QT4=	linguist_build moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/plugins
DESTDIRNAME=	INSTALL_ROOT

PLIST_SUB=	MYTHSHARE="share/mythtv"

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-all \
		--enable-mythmusic --enable-fftw --enable-opengl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/mythmusic/mythmusic/mythmusic.pro
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
