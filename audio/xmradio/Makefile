# New ports collection makefile for:	xmradio
# Version required:	0.5
# Date created:		2 Feb 1999
# Whom:			runge@rostock.zgdv.de
#
# $FreeBSD$
#

DISTNAME=	xmradio-0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.rostock.zgdv.de/~runge/radio/

MAINTAINER=	runge@rostock.zgdv.de

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

# This program does not actually depend on the below, but they are pretty
# useful if you are into digital audio recording and playback.
#RUN_DEPENDS=   sox:${PORTSDIR}/audio/sox

USE_IMAKE=	yes
REQUIRES_MOTIF=	yes

#post-install:
#              strip ${PREFIX}/bin/xmradio

.include <bsd.port.mk>
