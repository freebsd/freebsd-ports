# New ports collection makefile for:	xmradio
# Date created:		1 Oct 1999
# Whom:			runge@rostock.zgdv.de
#
# $FreeBSD$
#

PORTNAME=	xmradio
PORTVERSION=	0.8
CATEGORIES=	audio
MASTER_SITES=	http://www.egd.igd.fhg.de/~runge/radio/

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
