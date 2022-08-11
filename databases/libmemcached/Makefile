PORTNAME=	libmemcached
PORTVERSION=	1.0.18
PORTREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	https://launchpad.net/libmemcached/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C and C++ client library to the memcached server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent
TEST_DEPENDS=	memcached:databases/memcached

USES=		autoreconf gmake libtool localbase pathfix pkgconfig

CONFIGURE_ARGS=	--enable-libmemcachedprotocol \
		--without-memcached \
		--without-sphinx-build
CXXFLAGS+=	-D__STDC_CONSTANT_MACROS -pthread
GNU_CONFIGURE=	yes
LIBS+=		-lexecinfo
PATHFIX_MAKEFILEIN=	include.am
TEST_TARGET=	check
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	memdump # man/man1/memdump.1.gz

OPTIONS_DEFINE=	DEBUG MEMASLAP SASL
OPTIONS_GROUP=	HASH
OPTIONS_GROUP_HASH=	FNV64 HSIEH MURMUR
OPTIONS_DEFAULT=MEMASLAP SASL MURMUR FNV64
FNV64_DESC=	Enable fnv64 hashing
HSIEH_DESC=	Enable hsieh hashing
MEMASLAP_DESC=	Load generation and benchmark tool
MURMUR_DESC=	Enable murmur hashing

DEBUG_CONFIGURE_ENABLE=	debug
FNV64_CONFIGURE_ENABLE=	fnv64_hash
HSIEH_CONFIGURE_ENABLE=	hsieh_hash
MEMASLAP_CONFIGURE_ENABLE=	memaslap
MURMUR_CONFIGURE_ENABLE=murmur_hash
SASL_CONFIGURE_ENABLE=	sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

post-patch:
	@${REINPLACE_CMD} -e 's|%%LTLIBSASL2%%|${LTLIBSASL2}|' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
