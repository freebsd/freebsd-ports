# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	morse
PORTVERSION=	2.5
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.catb.org/~esr/morse/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Morse Code Trainer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/morsec bin/QSO man/man1/QSO.1.gz man/man1/morsec.1.gz

OPTIONS_SINGLE=	SOUND
OPTIONS_SINGLE_SOUND=	OSS X11 PULSEAUDIO
OPTIONS_DEFAULT=	OSS

OSS_DESC=	Beep using OSS (/dev/dsp)
X11_DESC=	Beep using X server
PULSEAUDIO_DESC=	Beep using Pulse Audio

OSS_MAKE_ARGS=	DEVICE=OSS

X11_MAKE_ARGS=	DEVICE=X11
X11_USES=	xorg
X11_USE=	XORG=x11
X11_CFLAGS=	-I${LOCALBASE}/include
X11_LDFLAGS=	-L${LOCALBASE}/lib

PULSEAUDIO_MAKE_ARGS=	DEVICE=PA
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_USES=	pkgconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/morse ${STAGEDIR}${PREFIX}/bin/morsec
	${INSTALL_PROGRAM} ${WRKSRC}/QSO ${STAGEDIR}${PREFIX}/bin/QSO
	${INSTALL_MAN} ${WRKSRC}/morse.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/morsec.1
	${INSTALL_MAN} ${WRKSRC}/QSO.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/QSO.1

.include <bsd.port.mk>
