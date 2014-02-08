# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	morse
PORTVERSION=	2.5
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.catb.org/~esr/morse/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	shurd@sasktel.net
COMMENT=	Morse Code Trainer

LICENSE=	BSD3CLAUSE

PLIST_FILES=	bin/morsec bin/QSO man/man1/QSO.1.gz man/man1/morsec.1.gz

OPTIONS_SINGLE=	SOUND
OPTIONS_SINGLE_SOUND=	OSS X11 PULSEAUDIO
OPTIONS_DEFAULT=	OSS

OSS_DESC=	Beep using OSS (/dev/dsp)
X11_DESC=	Beep using X server
PULSEAUDIO_DESC=	Beep using Pulse Audio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOSS}
MAKE_FLAGS+=	DEVICE=OSS

.elif ${PORT_OPTIONS:MX11}
MAKE_FLAGS+=	DEVICE=X11
USE_XORG=	x11
CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

.elif ${PORT_OPTIONS:MPULSEAUDIO}
MAKE_FLAGS+=	DEVICE=PA
LIB_DEPENDS+=	libpulse-simple.so:${PORTSDIR}/audio/pulseaudio
USES+=		pkgconfig
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/morse ${STAGEDIR}${PREFIX}/bin/morsec
	${INSTALL_PROGRAM} ${WRKSRC}/QSO ${STAGEDIR}${PREFIX}/bin/QSO
	${INSTALL_MAN} ${WRKSRC}/morse.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/morsec.1
	${INSTALL_MAN} ${WRKSRC}/QSO.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/QSO.1

.include <bsd.port.mk>
