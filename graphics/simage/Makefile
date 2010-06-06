# New ports collection makefile for:	simage
# Date created:				10 May 2002
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	simage
PORTVERSION=	1.6.1
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library with image format loaders and front-ends

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.6:${PORTSDIR}/graphics/png

USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-mpeg2enc
USE_LDCONFIG=	yes

.include <bsd.port.mk>
