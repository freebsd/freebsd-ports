PORTNAME=	libgdamm
PORTVERSION=	4.99.11
PORTREVISION=	3
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for libgda5 library
WWW=		https://www.gtkmm.org/

USES=		gmake libtool pkgconfig tar:xz compiler:c++11-lang gnome
USE_CXXSTD=	c++11
USE_GNOME=	libgda5 glibmm
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
BINARY_WRAPPERS=	gm4

OPTIONS_DEFINE=	BDB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB} || exists(${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc:databases/libgda5-bdb
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libgda-bdb-5.0.pc:databases/libgda5-bdb
PLIST_SUB+=	BDB=""
.else
PLIST_SUB+=	BDB=""
.endif

.include <bsd.port.mk>
