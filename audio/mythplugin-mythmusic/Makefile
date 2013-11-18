# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythmusic
PORTVERSION=	0.27
CATEGORIES=	audio
PKGNAMEPREFIX=	mythplugin-
DISTNAME=	mythtv-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Music playing plugin for MythTV

LIB_DEPENDS=	libcdio.so:${PORTSDIR}/sysutils/libcdio \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libtag.so:${PORTSDIR}/audio/taglib \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float
BUILD_DEPENDS=	mythfrontend:${PORTSDIR}/multimedia/mythtv

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_PROJECT=	mythtv
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-e9545c0/mythplugins

USE_QT4=	linguist_build moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/plugins
DESTDIRNAME=	INSTALL_ROOT

PLIST_SUB+=	MYTHSHARE="share/mythtv"

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
