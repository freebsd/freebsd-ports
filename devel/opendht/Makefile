PORTNAME=	opendht
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
PORTREVISION=	2
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
		libllhttp.so:www/llhttp \
		libnettle.so:security/nettle \
		libgnutls.so:security/gnutls
RUN_DEPENDS=	msgpack-cxx>0:devel/msgpack-cxx
TEST_DEPENDS=	cppunit>0:devel/cppunit

USES=		cmake:testing compiler:c++17-lang localbase ncurses pathfix pkgconfig readline ssl

USE_GITHUB=	yes
GH_ACCOUNT=	savoirfairelinux
USE_LDCONFIG=	yes

LDFLAGS+=	-lcrypto

CMAKE_OFF=	OPENDHT_STATIC BUILD_TESTING OPENDHT_TESTS_NETWORK
CMAKE_TESTING_ON=	BUILD_TESTING OPENDHT_TESTS_NETWORK # tests Tests assert and crash, see https://github.com/savoirfairelinux/opendht/issues/696

OPTIONS_DEFINE=			INDEX PROXY_CLIENT PROXY_SERVER PUSH_NOTIFICATIONS DOCS
OPTIONS_DEFAULT=		INDEX PROXY_CLIENT PROXY_SERVER PUSH_NOTIFICATIONS DOCS

INDEX_DESC=			Build DHT indexation feature
INDEX_CMAKE_BOOL=		OPENDHT_INDEX

PROXY_CLIENT_DESC=		Enable DHT proxy client
PROXY_CLIENT_CMAKE_BOOL=	OPENDHT_PROXY_CLIENT

PROXY_SERVER_DESC=		Enable DHT proxy server
PROXY_SERVER_CMAKE_BOOL=	OPENDHT_PROXY_SERVER
PROXY_SERVER_LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp \
				librestbed.so:www/restbed

PUSH_NOTIFICATIONS_DESC=	Enable push notifications support
PUSH_NOTIFICATIONS_CMAKE_BOOL=	OPENDHT_PUSH_NOTIFICATIONS

PORTDOCS=	*

# several tests fail, see https://github.com/savoirfairelinux/opendht/issues/721
# tests throw exceptions, see https://github.com/savoirfairelinux/opendht/issues/751

.include <bsd.port.mk>
