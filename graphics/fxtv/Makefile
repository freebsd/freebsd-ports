# New ports collection makefile for:	fxtv
# Version required:	0.48
# Date created:		Sun Sep  7 17:55:07 EDT 1997
# Whom:			Randall Hopper <rhh@ct.picker.com>
#
# $Id: Makefile,v 1.14 1998/11/25 09:01:17 asami Exp $
#

DISTNAME=	fxtv-0.48
CATEGORIES=	graphics
MASTER_SITES=	http://www.pagesz.net/~aa8vb/fxtv/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rhh@ct.picker.com

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff34 \
		Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d    \
		Xpm.4:${PORTSDIR}/graphics/xpm

# This program does not actually depend on the below, but they are pretty
# useful if you are into digital video recording and playback.
#RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
#		mpg123:${PORTSDIR}/audio/mpg123 \
#		mpeg_musicin:${PORTSDIR}/audio/mpegaudio \
#		mpeg_encode:${PORTSDIR}/graphics/mpeg_encode \
#		mplex:${PORTSDIR}/graphics/mplex

USE_X_PREFIX=	yes
USE_GMAKE=      yes
MAKE_FLAGS=	-e

.include <bsd.port.mk>
