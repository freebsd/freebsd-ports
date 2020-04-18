# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libumidi
PORTVERSION=	2.1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Universal general purpose MIDI library

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2 uidfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG JACK
OPTIONS_DEFAULT=JACK

JACK_MAKE_ARGS=	" HAVE_JACK=YES"
JACK_LIB_DEPENDS=	libjack.so:audio/jack
DEBUG_MAKE_ARGS=	" HAVE_DEBUG=YES"
MAKE_ARGS+=" HAVE_MAN=YES"

.include <bsd.port.mk>
