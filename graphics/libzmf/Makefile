# $FreeBSD$

PORTNAME=	libzmf
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	LODEV

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library that parses the file format of Zoner Callisto/Draw documents

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		libpng.so:graphics/png \
		librevenge-0.0.so:textproc/librevenge

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c++11-lang libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-tests --disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
