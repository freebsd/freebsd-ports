# $FreeBSD$

PORTNAME=	libfreehand
PORTVERSION=	0.1.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	LODEV

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library providing ability to interpret and import Adobe/Macromedia drawings

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	icu-config:devel/icu
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		librevenge-0.0.so:textproc/librevenge

GNU_CONFIGURE=	yes
USES=	compiler:c++11-lang gperf perl5 libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
CONFIGURE_ARGS=	--disable-werror --without-docs
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
