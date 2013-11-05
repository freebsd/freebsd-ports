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

LIB_DEPENDS=	libportaudio.so.2:${PORTSDIR}/audio/portaudio2 \
		libsndfile.so:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USES=		pkgconfig desktop-file-utils
USE_CSTD=	gnu89
USE_GNOME=	libglade2

.include <bsd.port.mk>
