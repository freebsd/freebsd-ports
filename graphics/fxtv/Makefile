# New ports collection makefile for:	fxtv
# Version required:	0.48
# Date created:		Sun Sep  7 17:55:07 EDT 1997
# Whom:			Randall Hopper <aa8vb@pagesz.net>
#
# $Id: Makefile,v 1.15 1999/02/06 07:32:58 markm Exp $
#

DISTNAME=	fxtv-0.48
CATEGORIES=	graphics
MASTER_SITES=	http://www.pagesz.net/~aa8vb/fxtv/
EXTRACT_SUFX=	.tgz

MAINTAINER=	aa8vb@pagesz.net

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff34 \
		Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d    \
		Xpm.4:${PORTSDIR}/graphics/xpm

# This program does not actually require the programs below, but they are 
# needed if you use digital video recording and playback.
#RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
#		mpg123:${PORTSDIR}/audio/mpg123 \
#		mpeg_musicin:${PORTSDIR}/audio/mpegaudio \
#		mpeg_encode:${PORTSDIR}/graphics/mpeg_encode \
#		mplex:${PORTSDIR}/graphics/mplex

USE_X_PREFIX=	yes
USE_GMAKE=      yes
MAKE_FLAGS=	-e

.include <bsd.port.mk>
