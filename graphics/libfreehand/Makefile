# $FreeBSD$

PORTNAME=	libfreehand
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	LODEV

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for interpreting and importing Adobe/Macromedia drawings

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs \
		cppunit-config:devel/cppunit \
		icu-config:devel/icu
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		librevenge-0.0.so:textproc/librevenge

GNU_CONFIGURE=	yes
USES=	compiler:c++11-lang gperf perl5 libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I ${LOCALBASE}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
