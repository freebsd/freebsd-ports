# New ports collection makefile for:	bmp-song_change
# Date created:				27 January, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmp-songchange
PORTVERSION=	0.0.1
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/bmp-plugins/
DISTNAME=	song_change-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Beep Media Player do-this-on-song-change plugin

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gtk20

PLIST_FILES=	lib/bmp/General/libsong_change.so

.include <bsd.port.mk>
