PORTNAME=	jack_ghero
DISTVERSIONPREFIX=	v
PORTVERSION=		1.0.4
PORTREVISION=	4
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon that converts a GuitarHero device into a JACK MIDI device
WWW=		https://github.com/hselasky/jack_ghero

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjack.so:audio/jack

USES=		tar:bzip2 uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

PLIST_FILES=	sbin/jack_ghero \
		share/man/man8/jack_ghero.8.gz

OPTIONS_DEFINE=	DEBUG

MAKE_ARGS+=	HAVE_MAN="YES"
MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"

.include <bsd.port.mk>
