# $FreeBSD$

PORTNAME=	libmemcached
PORTVERSION=	1.0.18
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	C and C++ client library to the memcached server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS?=	libevent.so:devel/libevent
TEST_DEPENDS=	memcached:databases/memcached

USES=		autoreconf execinfo gmake libtool localbase pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-memcached \
		--without-sphinx-build \
		--enable-libmemcachedprotocol

LIBS+=		-L${LOCALBASE}/lib -lexecinfo
CXXFLAGS+=	-D__STDC_CONSTANT_MACROS

OPTIONS_DEFINE=		DEBUG DTRACE MEMASLAP SASL
OPTIONS_DEFAULT=	MEMASLAP SASL MURMUR FNV64
OPTIONS_GROUP=		HASH
OPTIONS_GROUP_HASH=	FNV64 HSIEH MURMUR

DTRACE_DESC=	Enable DTrace support
MEMASLAP_DESC=	Load generation and benchmark tool
FNV64_DESC=	Enable fnv64 hashing
HSIEH_DESC=	Enable hsieh hashing
MURMUR_DESC=	Enable murmur hashing

DEBUG_CONFIGURE_ENABLE=		debug
DTRACE_CONFIGURE_ENABLE=	dtrace
MEMASLAP_CONFIGURE_ENABLE=	memaslap
FNV64_CONFIGURE_ENABLE=		fnv64_hash
HSIEH_CONFIGURE_ENABLE=		hsieh_hash
MURMUR_CONFIGURE_ENABLE=	murmur_hash

SASL_CONFIGURE_ENABLE=	sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

PATHFIX_MAKEFILEIN=	include.am

post-patch:
	@${REINPLACE_CMD} -e '/^LDFLAGS *=/ s/$$/ $${LTLIBSASL2}/' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/MAKE.*man/d' ${WRKSRC}/man/include.am

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*

regression-test: build
	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
