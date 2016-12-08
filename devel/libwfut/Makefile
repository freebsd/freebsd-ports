# Created by: Oliver Lehmann
# $FreeBSD$

PORTNAME=	libwfut
PORTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/libwfut%20%28updates%20library%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge update library

LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20 \
		libcurl.so:ftp/curl

CONFIGURE_ARGS+=--without-python
GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig compiler:c++11-lib
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/ python//g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
