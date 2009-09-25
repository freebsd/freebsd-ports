# Ports collection makefile for:	mpdas
# Date created:				Nov 11, 2008
# Whom:					hrkfrd@googlemail.com
#
# $FreeBSD$
#

PORTNAME=	mpdas
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://50hz.ws/mpdas/

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	MPD AudioScrobbler written in C++ supporting the latest protocol

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		mpd:${PORTSDIR}/audio/libmpd

USE_GNOME=	pkgconfig
USE_BZIP2=	yes

PLIST_FILES=	bin/mpdas

MAN1=		mpdas.1
MANCOMPRESSED=	no

.include <bsd.port.mk>
