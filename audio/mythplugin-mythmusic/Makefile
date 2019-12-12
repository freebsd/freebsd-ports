# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythmusic
DISTVERSIONPREFIX=	v
DISTVERSION=	30.0
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMEPREFIX=	mythplugin-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music playing plugin for MythTV

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libmyth-30.so:multimedia/mythtv

USES=		gmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_PROJECT=	mythtv
USE_LDCONFIG=	yes
USE_QT=		buildtools_build core gui qmake_build sql xml

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}" --cxx="${CXX}" \
		--disable-all \
		--enable-mythmusic
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" \
		QTDIR="${PREFIX}" PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
MAKE_ENV=	QTDIR="${PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"
DESTDIRNAME=	INSTALL_ROOT
PLIST_SUB=	MYTHSHARE="share/mythtv"
WRKSRC_SUBDIR=	mythplugins

OPTIONS_DEFINE=	CDIO FFTW

CDIO_LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
			libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_CONFIGURE_ENABLE=	cdio

FFTW_DESC=		FFTW3-based visualizations
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_CONFIGURE_ENABLE=	fftw

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/mythmusic/mythmusic/mythmusic.pro
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mythtv/plugins/libmythmusic.so

.include <bsd.port.mk>
