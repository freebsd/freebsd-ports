# New ports collection makefile for:	fxtv
# Date created:		Thu Nov  4 19:54:04 EST 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	fxtv
PORTVERSION=	1.02
CATEGORIES=	graphics
MASTER_SITES=	http://www.ipass.net/~dbhopper/aa8vb/fxtv/
EXTRACT_SUFX=	.tgz

MAINTAINER=	aa8vb@ipass.net

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d    \
		Xpm.4:${PORTSDIR}/graphics/xpm

NOT_FOR_ARCHS=	alpha

# This program does not actually require the programs below unless you
#   use audio/video recording and/or playback and save to a non-raw format.
#RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
#		mpg123:${PORTSDIR}/audio/mpg123 \
#		mpeg_musicin:${PORTSDIR}/audio/mpegaudio \
#		mpeg_encode:${PORTSDIR}/graphics/mpeg_encode \
#		mplex:${PORTSDIR}/graphics/mplex

USE_X_PREFIX=	yes
USE_GMAKE=      yes
MAKE_FLAGS=	-e
MAN1=		fxtv.1

pre-install:
	${CP} ${WRKSRC}/fxtv.1 ${WRKSRC}/fxtv.man

.include <bsd.port.mk>
