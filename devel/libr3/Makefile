# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	libr3
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	URL router library with high performance

LICENSE=	MIT

LIB_DEPENDS=	libcheck.so:devel/libcheck \
		libgvc.so:graphics/graphviz \
		libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-graphviz
USES=		autoreconf libtool pathfix pkgconfig
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	c9s
GH_PROJECT=	r3

.include <bsd.port.mk>
