PORTNAME=	liborcus
PORTVERSION=	0.18.1
CATEGORIES=	devel misc
MASTER_SITES=	https://kohei.us/files/orcus/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Standalone file import filter library for spreadsheet documents
WWW=		https://gitlab.com/orcus/orcus

LICENSE=	MPL20

BUILD_DEPENDS=	mdds>=2.1:devel/mdds
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libixion-0.18.so:textproc/libixion

USES=		autoreconf compiler:c++17-lang gmake libtool \
		localbase:ldflags pathfix pkgconfig tar:xz

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-werror \
		--with-boost="${LOCALBASE}" \
		--with-boost-system=boost_system \
		--disable-python

OPTIONS_DEFINE=	STATIC
OPTIONS_DEFAULT=STATIC
OPTIONS_SUB=	yes

STATIC_CONFIGURE_ENABLE=	static

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
