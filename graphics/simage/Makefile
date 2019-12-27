# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=	simage
PORTVERSION=	1.7.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/Coin3D/coin/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library with image format loaders and front-ends

LICENSE=	MIT unknown
LICENSE_COMB=	dual
LICENSE_NAME_unknown=	mpeg2enc
LICENSE_TEXT_unknown=	${FILESDIR}/LICENSE.mpeg2enc
LICENSE_PERMS_unknown=	no-dist-sell no-pkg-sell

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libjasper.so:graphics/jasper \
		libgif.so:graphics/giflib \
		libpng.so:graphics/png

USES=		jpeg libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mpeg2enc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
