# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=	simage
PORTVERSION=	1.7.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/Coin3D/coin/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library with image format loaders and front-ends

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libpng15.so:${PORTSDIR}/graphics/png

USES=		pathfix libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mpeg2enc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
