# New ports collection makefile for:	clementine-player
# Date created:		2010-03-23
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	clementine
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-player

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	A cross-platform music player based on Amarok 1.4

LICENSE=	GPLv3

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		notify.4:${PORTSDIR}/devel/libnotify \
		xine.1:${PORTSDIR}/multimedia/libxine \
		qjson.0:${PORTSDIR}/devel/qjson
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

PROJECTHOST=	${PORTNAME}${PKGNAMESUFFIX}

USE_CMAKE=	yes
USE_ICONV=	yes
USE_GL=		glew
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build \
		linguist_build network sql opengl dbus qtestlib corelib
USE_GCC=	4.2+
INSTALLS_ICONS=	yes
USE_GSTREAMER=	gio ogg mp3 flac soup vorbis
MAKE_JOBS_UNSAFE=	yes

CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib:${PREFIX}/lib"

OPTIONS=	VISUALISATION "Visualisations from projectM" off \
		LASTFM "Support Last.fm service (requires ruby)" on \
		GPOD "iPod support" on \
		MTP "MTP device support" on

.include <bsd.port.pre.mk>

.if defined(WITH_VISUALISATION)
PLIST_SUB+=	VSL=""
.else
CMAKE_ARGS+=	-DENABLE_VISUALISATIONS=OFF
PLIST_SUB+=	VSL="@comment "
.endif

.if defined(WITH_LASTFM)
LIB_DEPENDS+=	lastfm.0:${PORTSDIR}/audio/liblastfm
.else
CMAKE_ARGS+=	-DENABLE_LIBLASTFM=Off
.endif

.if defined(WITH_GPOD)
LIB_DEPENDS+=	gpod.7:${PORTSDIR}/audio/libgpod
.else
CMAKE_ARGS+=	-DENABLE_LIBGPOD=Off
.endif

.if defined(WITH_MTP)
LIB_DEPENDS+=	mtp.11:${PORTSDIR}/audio/libmtp
.else
CMAKE_ARGS+=	-DENABLE_LIBMTP=Off
.endif

.include <bsd.port.post.mk>
