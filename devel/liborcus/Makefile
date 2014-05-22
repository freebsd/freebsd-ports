# $FreeBSD$

PORTNAME=	liborcus
PORTVERSION=	0.5.2
CATEGORIES=	devel misc
MASTER_SITES=	http://kohei.us/files/orcus/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/mdds/global.hpp:${PORTSDIR}/devel/mdds
LIB_DEPENDS=	libzip.so:${PORTSDIR}/archivers/libzip \
		libboost_system.so:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-spreadsheet-model --disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system
CONFIGURE_ENV=	ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-lz"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
