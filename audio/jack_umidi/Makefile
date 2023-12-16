PORTNAME=	jack_umidi
PORTVERSION=	1.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon that converts a raw MIDI device into a JACK MIDI device
WWW=		https://github.com/hselasky/jack_umidi

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjack.so:audio/jack

USES=		tar:bzip2 uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

MAKE_ARGS+=	HAVE_MAN="YES" \
		PTHREAD_LIBS="-lpthread"

SUB_FILES=	jack_umidi.conf

PLIST_FILES=	man/man8/jack_umidi.8.gz \
		sbin/jack_umidi

OPTIONS_DEFINE=	DEBUG DEVD_SCRIPT

DEVD_SCRIPT_DESC=		Install devd script to auto-launch jack_umidi
DEBUG_MAKE_ARGS=		HAVE_DEBUG="YES"
DEVD_SCRIPT_PLIST_FILES=	etc/devd/jack_umidi.conf

post-install-DEVD_SCRIPT-on::
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${WRKDIR}/jack_umidi.conf \
		 ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
