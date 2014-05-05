# Created by: Michael Nottebrock <michaelnottebrock@gmx.net>
# $FreeBSD$

PORTNAME=	ices
PORTVERSION=	2.0.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/${PORTNAME}/ \
		http://svn.xiph.org/releases/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Vorbis streaming source client for icecast 2

LICENSE=	GPLv2

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
		libshout.so:${PORTSDIR}/audio/libshout \
		libspeex.so:${PORTSDIR}/audio/speex \
		libtheora.so:${PORTSDIR}/multimedia/libtheora \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

OPTIONS_DEFINE=	ALSA

CONFIGURE_ARGS=	--disable-roaraudio --disable-sun-audio
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -pthread
USE_GNOME=	libxml2
USES=		gmake iconv pkgconfig tar:bzip2

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa

.include <bsd.port.mk>
