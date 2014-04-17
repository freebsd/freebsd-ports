# Created by: Sean Bruno <sbruno@freebsd.org>
# $FreeBSD$

PORTNAME=	libshout
PORTVERSION=	2.3.1
CATEGORIES=	audio python
MASTER_SITES=	SF/idjc/libshout-idjc/
DISTNAME=	${PORTNAME}-idjc-${PORTVERSION}

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Shoutcast/Icecast Library for audio/idjc

LICENSE=	LGPL20

LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg \
		libspeex.so:${PORTSDIR}/audio/speex

HAS_CONFIGURE=	yes
USES=		pkgconfig pathfix
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	no

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BROKEN=		audio/shout-idjc IPv6 problem on compile in sock.c
.endif

# 10 and higer seem to be fine
.if ${OSVERSION} < 1000000
USE_GCC=	4.6+
.endif

.include <bsd.port.post.mk>
