# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	gnaural
PORTVERSION=	1.0.20110606
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Gnaural/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Binaural beat generator

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	portaudio:${PORTSDIR}/audio/portaudio2 \
		sndfile:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_GNOME=	libglade2 desktopfileutils

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
