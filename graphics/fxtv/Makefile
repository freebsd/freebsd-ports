# New ports collection makefile for:	fxtv
# Version required:	0.47
# Date created:		Sun Sep  7 17:55:07 EDT 1997
# Whom:			Randall Hopper <rhh@ct.picker.com>
#
# $Id: Makefile,v 1.6 1998/07/06 13:26:32 dburr Exp $
#

DISTNAME=	fxtv-0.47
CATEGORIES=	graphics x11
MASTER_SITES=	http://multiverse.com/~rhh/fxtv/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rhh@ct.picker.com

LIB_DEPENDS=	tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34 \
		Xaw3d\\.6\\.:${PORTSDIR}/x11/Xaw3d    \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

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
