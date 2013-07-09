# Created by: runge@rostock.zgdv.de
# $FreeBSD$

PORTNAME=	xmradio
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://core.de/~coto/radio/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif based FM tuner (for use with bt848 driver)

# This program does not actually depend on the below, but they are pretty
# useful if you are into digital audio recording and playback.
#RUN_DEPENDS=   sox:${PORTSDIR}/audio/sox

USES=		imake motif
USE_XORG=	xpm
ONLY_FOR_ARCHS=	i386 ia64

PLIST_FILES=	bin/xmradio lib/X11/app-defaults/XMradio

post-patch:
	${REINPLACE_CMD} -e "s,machine/ioctl_bt848.h,dev/bktr/ioctl_bt848.h," \
		${WRKSRC}/radio.c
#
#post-install:
#              ${STRIP_CMD} ${PREFIX}/bin/xmradio

.include <bsd.port.mk>
