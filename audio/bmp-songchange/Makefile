# New ports collection makefile for:	bmp-song_change
# Date created:				27 January, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmp-songchange
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/bmp-plugins/

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	Beep Media Player do-this-on-song-change plugin

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15

PLIST_FILES=	lib/bmp/General/libsong_change.so

.include <bsd.port.mk>
