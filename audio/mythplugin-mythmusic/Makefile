# New ports collection makefile for:	mythplugin-mythmusic
# Date created:		2010-03-07
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	mythmusic
PORTVERSION=	0.25.2
CATEGORIES=	audio
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.osuosl.org/pub/mythtv/old_releases/ \
		http://ftp.oregonstate.edu/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/old_releases/
PKGNAMEPREFIX=	mythplugin-
DISTNAME=	mythplugins-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Music playing plugin for MythTV

LIB_DEPENDS=	cdio.13:${PORTSDIR}/sysutils/libcdio \
		FLAC.10:${PORTSDIR}/audio/flac \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		tag.1:${PORTSDIR}/audio/taglib \
		fftw3f:${PORTSDIR}/math/fftw3-float
BUILD_DEPENDS=	mythfrontend:${PORTSDIR}/multimedia/mythtv

USE_BZIP2=	yes
USE_QT4=	linguist_build moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/plugins

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
