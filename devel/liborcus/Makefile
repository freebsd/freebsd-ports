# $FreeBSD$

PORTNAME=	liborcus
PORTVERSION=	0.5.1
CATEGORIES=	devel misc
MASTER_SITES=	http://kohei.us/files/orcus/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/mdds/global.hpp:${PORTSDIR}/devel/mdds
LIB_DEPENDS=	zip:${PORTSDIR}/archivers/libzip \
		boost_system:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

CONFIGURE_ARGS=	--disable-spreadsheet-model --disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system
CONFIGURE_ENV=	ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-lz"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
