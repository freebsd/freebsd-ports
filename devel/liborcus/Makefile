PORTNAME=	liborcus
PORTVERSION=	0.17.2
CATEGORIES=	devel misc
MASTER_SITES=	https://kohei.us/files/orcus/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents

LICENSE=	MPL20

BUILD_DEPENDS=	mdds>0:devel/mdds
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libixion-0.17.so:textproc/libixion

USES=		autoreconf compiler:c++11-lib libtool localbase:ldflags \
		pathfix pkgconfig tar:xz

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system \
		--disable-python

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
