# $FreeBSD$

PORTNAME=	liborcus
PORTVERSION=	0.7.1
CATEGORIES=	devel misc
MASTER_SITES=	http://kohei.us/files/orcus/src/
PKGNAMESUFFIX=	07

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/mdds/global.hpp:devel/mdds0
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

BROKEN_sparc64=	cannot link with boost
BROKEN_powerpc64=	Does not build

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-spreadsheet-model --disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system
CONFIGURE_ENV=	ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-lz"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-stage:
	@${RM} -f ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
