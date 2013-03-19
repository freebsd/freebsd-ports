# $FreeBSD$

PORTNAME=	liborcus
PORTVERSION=	0.3.0
CATEGORIES=	devel misc
MASTER_SITES=	http://kohei.us/files/orcus/src/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/mdds/global.hpp:${PORTSDIR}/devel/mdds
LIB_DEPENDS=	zip:${PORTSDIR}/archivers/libzip \
		boost_system:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=	pathfix
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build

CONFIGURE_ARGS=	--disable-spreadsheet-model --disable-werror \
		--with-boost-system=boost_system
CONFIGURE_ENV=	ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-lz"
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
