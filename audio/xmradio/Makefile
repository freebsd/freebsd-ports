# New ports collection makefile for:	xmradio
# Date created:		1 Oct 1999
# Whom:			runge@rostock.zgdv.de
#
# $FreeBSD$
#

PORTNAME=	xmradio
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	http://core.de/~coto/radio/

MAINTAINER=	g.gonter@ieee.org
COMMENT=	Motif based FM tuner (for use with bt848 driver)

# This program does not actually depend on the below, but they are pretty
# useful if you are into digital audio recording and playback.
#RUN_DEPENDS=   sox:${PORTSDIR}/audio/sox

USE_IMAKE=	yes
USE_XPM=	yes
USE_MOTIF=	yes

PLIST_FILES=	bin/xmradio lib/X11/app-defaults/XMradio

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
ONLY_FOR_ARCHS=	i386
.else
ONLY_FOR_ARCHS=	alpha i386 ia64
.endif

#
#post-install:
#              ${STRIP_CMD} ${PREFIX}/bin/xmradio

.include <bsd.port.post.mk>
