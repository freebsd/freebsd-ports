# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libumidi
PORTVERSION=	2.0.11
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Universal general purpose MIDI library

LICENSE=	BSD2CLAUSE
USE_BZIP2=	yes

OPTIONS_DEFINE=	DEBUG JACK
OPTIONS_DEFAULT=JACK

USES=		uidfix

JACK_MAKE_ARGS=	" HAVE_JACK=YES"
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
DEBUG_MAKE_ARGS=	" HAVE_DEBUG=YES"
MAKE_ARGS+=" HAVE_MAN=YES"

.include <bsd.port.mk>
