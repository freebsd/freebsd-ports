# $FreeBSD$

PORTNAME=	msilbc
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	SAVANNAH/linphone/plugins/sources/

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Mediastreamer plugin for the iLBC audio codec

LIB_DEPENDS=	libortp.so:net/ortp \
		libmediastreamer_base.so:net/mediastreamer \
		libilbc.so:net/ilbc

USES=		libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ILBC_CFLAGS=-I${LOCALBASE}/include/ilbc \
		ILBC_LIBS="-L${LOCALBASE}/lib -lilbc"
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
