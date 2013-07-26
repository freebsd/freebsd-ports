# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libumidi
PORTVERSION=	2.0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A universal general purpose MIDI library

LICENSE=	BSD
USE_BZIP2=	yes
MAN3=		umidi20.3
MANCOMPRESSED=	yes

OPTIONS_DEFINE=	DEBUG JACK
.include <bsd.port.options.mk>

MAKE_ARGS+=" PTHREAD_LIBS=${PTHREAD_LIBS}"

.if ${PORT_OPTIONS:MJACK}
MAKE_ARGS+=" HAVE_JACK=YES"
LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

MAKE_ARGS+=" HAVE_MAN=YES"

.include <bsd.port.mk>
