# Created by: Michael Nottebrock <michaelnottebrock@gmx.net>
# $FreeBSD$

PORTNAME=	ices
PORTVERSION=	2.0.2
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/ices/ \
		http://svn.xiph.org/releases/ices/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vorbis streaming source client for icecast 2

LICENSE=	GPLv2

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		shout:${PORTSDIR}/audio/libshout2 \
		vorbis:${PORTSDIR}/audio/libvorbis \
		speex:${PORTSDIR}/audio/speex \
		theora:${PORTSDIR}/multimedia/libtheora

OPTIONS_DEFINE=	ALSA

USES=		pkgconfig iconv gmake
USE_BZIP2=	yes
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-roaraudio --disable-sun-audio

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=--disable-alsa
.endif

.include <bsd.port.mk>
