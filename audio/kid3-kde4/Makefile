# New ports collection makefile for:   kid3
# Date created:                2006-08-02
# Whom:                        Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kid3
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	SF
PKGNAMESUFFIX=	-kde4

MAINTAINER=	makc@FreeBSD.org
COMMENT=	MP3/Ogg/FLAC tag editor for KDE

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		FLAC.10:${PORTSDIR}/audio/flac \
		ogg.6:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		tunepimp.5:${PORTSDIR}/audio/libtunepimp \
		mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	svg gui network dbus xml \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include" \
		-DCMAKE_REQUIRED_LIBRARIES:STRING="${PTHREAD_LIBS}"

.include <bsd.port.mk>
