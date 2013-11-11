# Created by: Mirko Zinn <mail@derzinn.de>
# $FreeBSD$

PORTNAME=	mongodb
PORTVERSION=	2.4.8
CATEGORIES=	databases net
MASTER_SITES=	http://downloads.mongodb.org/src/
DISTNAME=	${PORTNAME}-src-r${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	NOSQL distributed document-oriented database

# mongodb is AGPLv3, C++ driver is AL2
LICENSE=	AGPLv3 AL2
LICENSE_COMB=	multi

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libsnappy.so:${PORTSDIR}/archivers/snappy
# boost 1.52 from ports make mongod segfaulting with many tests
# LIB_DEPENDS+=	libboost_system.so:${PORTSDIR}/devel/boost-libs
# SCONS_ARGS+=	--use-system-boost

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than i386 and amd64"

OPTIONS_DEFINE=	SM SSL SASL TEST
OPTIONS_DEFAULT=SSL
SM_DESC=	Use SpiderMonkey instead of V8 for JavaScript
TEST_DESC=	Add support for running regression test

USE_SCONS=	yes
SCONS_ARGS=	--prefix=${STAGEDIR}${PREFIX} --cc=${CC} --cxx=${CXX} \
		--use-system-pcre --use-system-snappy \
		--full --sharedclient

USERS=	mongodb
GROUPS=	mongodb

USE_RC_SUBR=	mongod

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSM}
SCONS_ARGS+=	--usesm --use-system-sm
LIB_DEPENDS+=	libjs.so:${PORTSDIR}/lang/spidermonkey17
.else
SCONS_ARGS+=	--usev8 --use-system-v8
LIB_DEPENDS+=	libv8.so:${PORTSDIR}/lang/v8
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
SCONS_ARGS+=	--ssl
.endif

.if ${PORT_OPTIONS:MSASL}
SCONS_ARGS+=	--use-sasl-client
LIB_DEPENDS+=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
.endif

.if ${PORT_OPTIONS:MTEST}
BUILD_DEPENDS=	pymongo>=2.5:${PORTSDIR}/databases/pymongo
SCONS_TARGET=	all
SMOKE_TESTS=	smokeAll smokeCppUnittests
.	if ${PORT_OPTIONS:MSSL}
SMOKE_TESTS+=	smokeSsl
.	endif
.else
SCONS_TARGET=	core tools
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000024
EXTRA_PATCHES=	${PATCHDIR}/clang-patch-src_mongo_db_fts_stemmer.cpp \
		${PATCHDIR}/clang-patch-src_mongo_platform_unordered_map.h \
		${PATCHDIR}/clang-patch-src_mongo_platform_unordered_set.h \
		${PATCHDIR}/clang-patch-src_third_party_s2_hash.h
.endif

post-patch:
	@${REINPLACE_CMD} 's/\["-O3"\]/"${CFLAGS}"/' \
		${WRKSRC}/SConstruct

.if ${PORT_OPTIONS:MTEST}
test: build-depends build
	@cd ${BUILD_WRKSRC} && \
		${SCONS_BIN} ${SCONS_ENV} ${SCONS_ARGS} ${SMOKE_TESTS}
.endif

.include <bsd.port.mk>
