# New ports collection makefile for:	xmms-arts_output
# Date created:				12 Nov 2003
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	xmms-
PORTNAME=	arts_output
PORTVERSION=	0.7.1
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://havardk.xmms.org/plugins/arts_output/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	aRts output plugin for XMMS.

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		artsc.0:${PORTSDIR}/audio/arts

USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
PLIST_FILES=	lib/xmms/Output/libarts.a \
		lib/xmms/Output/libarts.la \
		lib/xmms/Output/libarts.so \
		bin/xmms-arts-helper

.include <bsd.port.mk>
