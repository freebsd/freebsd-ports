# $FreeBSD$

PORTNAME=	liborcus
PORTVERSION=	0.14.1
PORTREVISION=	4
CATEGORIES=	devel misc
MASTER_SITES=	http://kohei.us/files/orcus/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents

LICENSE=	MPL20

BUILD_DEPENDS=	mdds>0:devel/mdds
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		compiler:c++11-lib libtool localbase:ldflags \
		pathfix pkgconfig tar:xz

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-spreadsheet-model --disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system \
		--disable-python

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
