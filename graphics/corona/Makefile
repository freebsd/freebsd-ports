# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	corona
PORTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics library that supports most image formats

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so.11:${PORTSDIR}/graphics/jpeg

USE_AUTOTOOLS=	libtool
USE_GNOME=	lthack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LIBS="${LIBS} -L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wall||' \
		${WRKSRC}/configure

.include <bsd.port.mk>
