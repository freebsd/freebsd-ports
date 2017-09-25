# $FreeBSD$

PORTNAME=	liborcus
PORTVERSION=	0.12.1
PORTREVISION=	4
CATEGORIES=	devel misc
MASTER_SITES=	http://kohei.us/files/orcus/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/mdds-1.2/mdds/global.hpp:devel/mdds
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

BROKEN_powerpc64=	fails to configure: checking for the Boost program_options library... no

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-spreadsheet-model --disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system \
		--disable-python
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
