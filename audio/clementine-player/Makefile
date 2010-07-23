# New ports collection makefile for:	clementine-player
# Date created:		2010-03-23
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	clementine
PORTVERSION=	0.4.2
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-player

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	A cross-platform music player based on Amarok 1.4

LIB_DEPENDS=	lastfm.0:${PORTSDIR}/audio/liblastfm \
		tag.1:${PORTSDIR}/audio/taglib \
		notify.1:${PORTSDIR}/devel/libnotify \
		xine.1:${PORTSDIR}/multimedia/libxine
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
USE_GSTREAMER=	gio ogg mp3 flac soup
MAKE_JOBS_SAFE=	yes

OPTIONS=	VISUALISATION "Visualisations from projectM" off

.include <bsd.port.pre.mk>

.if defined(WITH_VISUALISATION)
PLIST_SUB+=	VSL=""
.else
CMAKE_ARGS+=	-DENABLE_VISUALISATIONS=OFF
PLIST_SUB+=	VSL="@comment "
.endif

.include <bsd.port.post.mk>
