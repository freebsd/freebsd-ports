PORTNAME=	libetonyek
PORTVERSION=	0.1.9
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	LODEV/${PORTNAME}
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library to interpret and import Apple Keynote presentations

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/mdds-${MDDS_VERSION}/mdds/global.hpp:devel/mdds \
		${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		librevenge-0.0.so:textproc/librevenge \
		liblangtag.so:devel/liblangtag \
		libxml2.so:textproc/libxml2

USES=		compiler:c++11-lib gmake libtool pathfix \
		pkgconfig tar:xz

MDDS_VERSION=	1.7

CONFIGURE_ARGS=	--disable-tests --disable-werror --without-docs --with-mdds=${MDDS_VERSION}
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
