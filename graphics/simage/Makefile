# New ports collection makefile for:	simage
# Date created:				10 May 2002
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	simage
PORTVERSION=	1.6.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library with image format loaders and front-ends

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png

USE_XLIB=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-mpeg2enc
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
