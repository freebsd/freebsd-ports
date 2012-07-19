# New ports collection makefile for:	simage
# Date created:				10 May 2002
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	simage
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.coin3d.org/coin/src/all/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library with image format loaders and front-ends

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		gif.5:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-mpeg2enc
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
