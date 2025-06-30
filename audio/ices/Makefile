PORTNAME=	ices
PORTVERSION=	2.0.3
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	https://downloads.xiph.org/releases/ices/ \
		https://ftp.osuosl.org/pub/xiph/releases/ices/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Vorbis streaming source client for icecast 2
WWW=		https://icecast.org/ices/ \
		https://gitlab.xiph.org/xiph/icecast-ices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libshout.so:audio/libshout \
		libspeex.so:audio/speex \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		gmake gnome iconv pkgconfig tar:bzip2
USE_GNOME=	libxml2

CONFIGURE_ARGS=	--disable-roaraudio --disable-sun-audio
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	ALSA

ALSA_CONFIGURE_ENABLE=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

.include <bsd.port.mk>
