# New ports collection makefile for:	gnaural
# Date created:		25 Jan 2012
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	gnaural
PORTVERSION=	1.0.20110606
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Gnaural/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Binaural beat generator

LICENSE=	GPLv2

LIB_DEPENDS=	portaudio:${PORTSDIR}/audio/portaudio2 \
		sndfile:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USE_GNOME=	libglade2 desktopfileutils

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
