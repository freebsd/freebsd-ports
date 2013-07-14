# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jack_umidi
PORTVERSION=	1.0.4
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Daemon that converts a raw MIDI device into a JACK MIDI device

LICENSE=	BSD

LIB_DEPENDS=	jack:${PORTSDIR}/audio/jack

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
MANCOMPRESSED=	yes
MAN8=		jack_umidi.8

PLIST_FILES=	sbin/jack_umidi

OPTIONS_DEFINE=        DEBUG

.include <bsd.port.options.mk>

MAKE_ARGS+=" HAVE_MAN=YES"
MAKE_ARGS+=" PTHREAD_LIBS=${PTHREAD_LIBS}"

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

.include <bsd.port.mk>
