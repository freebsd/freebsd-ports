PORTNAME=	opendht
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.6
CATEGORIES=	devel net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight Distributed Hash Table implementation
WWW=		https://github.com/savoirfairelinux/opendht/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/asio.hpp:net/asio \
		boost-libs>0:devel/boost-libs \
		msgpack-cxx>0:devel/msgpack-cxx \
		restinio>0:www/restinio
LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libfmt.so:devel/libfmt \
		libhttp_parser.so:www/http-parser \
		libjsoncpp.so:devel/jsoncpp \
		libnettle.so:security/nettle \
		libgnutls.so:security/gnutls
RUN_DEPENDS=	msgpack-cxx>0:devel/msgpack-cxx
TEST_DEPENDS=	cppunit>0:devel/cppunit

USES=		cmake:testing compiler:c++17-lang localbase ncurses pathfix pkgconfig readline ssl

USE_GITHUB=	yes
GH_ACCOUNT=	savoirfairelinux
USE_LDCONFIG=	yes

LDFLAGS+=	-lcrypto

CMAKE_OFF=	OPENDHT_STATIC BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING # tests fail w/out explanation, see https://github.com/savoirfairelinux/opendht/issues/640, https://github.com/savoirfairelinux/opendht/issues/658

OPTIONS_DEFINE=	PROXY_SERVER PROXY_CLIENT PUSH_NOTIFICATIONS DOCS

PROXY_SERVER_DESC=		Enable DHT proxy server
PROXY_CLIENT_DESC=		Enable DHT proxy client
PUSH_NOTIFICATIONS_DESC=	Enable push notifications support

PROXY_SERVER_CMAKE_BOOL=	OPENDHT_PROXY_SERVER
PROXY_CLIENT_CMAKE_BOOL=	OPENDHT_PROXY_CLIENT
PUSH_NOTIFICATIONS_CMAKE_BOOL=	OPENDHT_PUSH_NOTIFICATIONS

PROXY_SERVER_LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp \
				librestbed.so:www/restbed

PORTDOCS=	*

.include <bsd.port.mk>
