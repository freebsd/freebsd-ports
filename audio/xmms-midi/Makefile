# New ports collection makefile for:	xmms-midi
# Date created:		2002-10-14
# Whom:			Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$

PORTNAME=	xmms-midi
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://dl.fkb.wormulon.net/xmms-midi/ \
				http://dl.kel.wormulon.net/xmms-midi/

MAINTAINER=	hendrik@scholz.net
COMMENT=	XMMS input plugin to play midi files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	automake:14 autoconf:213 libtool:15

PLIST_FILES=	lib/xmms/Input/libmid.a \
		lib/xmms/Input/libmid.la \
		lib/xmms/Input/libmid.so

.include <bsd.port.mk>
