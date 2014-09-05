# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jack_ghero
PORTVERSION=	1.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Daemon that converts a GuitarHero device into a JACK MIDI device

LICENSE=	BSD

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

USES=		tar:bzip2 uidfix

PLIST_FILES=	sbin/jack_ghero \
		man/man8/jack_ghero.8.gz

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

MAKE_ARGS+=" HAVE_MAN=YES"
MAKE_ARGS+=" PTHREAD_LIBS=${PTHREAD_LIBS}"

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

.include <bsd.port.mk>
