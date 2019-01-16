# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythmusic
DISTVERSIONPREFIX=	v
DISTVERSION=	29.1
PORTREVISION=	2
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
		libmyth-29.so:multimedia/mythtv

USES=	qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_PROJECT=	mythtv
USE_LDCONFIG=	yes
USE_QT=		buildtools_build core gui qmake_build sql xml

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-all \
		--enable-mythmusic
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mythtv/plugins/libmythmusic.so

.include <bsd.port.mk>
