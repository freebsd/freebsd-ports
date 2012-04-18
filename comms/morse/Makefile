# New ports collection makefile for:	morse
# Date created:		2012-04-11
# Whom:			Stephen Hurd <shurd@sasktel.net>
#
# $FreeBSD$
#

PORTNAME=	morse
PORTVERSION=	2.4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.catb.org/~esr/morse/

MAINTAINER=	shurd@sasktel.net
COMMENT=	Morse Code Trainer

MAN1=		morsec.1 QSO.1
PLIST_FILES=	bin/morsec \
		bin/QSO

OPTIONS=	OSS "Beep using OSS (/dev/dsp)"	on \
		X11 "Beep using X server"	off \
		PA  "Beep using Pulse Audio"	off

.include <bsd.port.options.mk>

.if defined(WITH_OSS)
MAKE_FLAGS+=	DEVICE=OSS

.if defined(WITH_X11) || defined(WITH_PA)
BROKEN=	Only one sound output method must be chosen.
.endif

.elif defined(WITH_X11)
MAKE_FLAGS+=	DEVICE=X11
USE_XORG=	x11
CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

.if defined(WITH_OSS) || defined(WITH_PA)
BROKEN=	Only one sound output method must be chosen.
.endif

.elif defined(WITH_PA)
MAKE_FLAGS+=	DEVICE=PA
LIB_DEPENDS+=	pulse-simple:${PORTSDIR}/audio/pulseaudio
USE_GNOME=	pkgconfig

.if defined(WITH_OSS) || defined(WITH_X11)
BROKEN=	Only one sound output method must be chosen.
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/morse ${PREFIX}/bin/morsec
	${INSTALL_PROGRAM} ${WRKSRC}/QSO ${PREFIX}/bin/QSO
	${INSTALL_MAN} ${WRKSRC}/morse.1 ${MAN1PREFIX}/man/man1/morsec.1
	${INSTALL_MAN} ${WRKSRC}/QSO.1 ${MAN1PREFIX}/man/man1/QSO.1

.include <bsd.port.mk>
