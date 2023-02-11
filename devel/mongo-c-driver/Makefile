PORTNAME=	mongo-c-driver
PORTVERSION=	1.23.2
CATEGORIES=	devel

MAINTAINER=	ports@bsdserwis.com
COMMENT=	C Driver for MongoDB
WWW=		https://github.com/mongodb/mongo-c-driver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:noninja cpe pkgconfig
USE_GITHUB=	yes
CPE_VENDOR=	mongodb
GH_ACCOUNT=	mongodb
USE_LDCONFIG=	yes

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libbson-1.0.so:devel/libbson \
		libzstd.so:archivers/zstd
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
DOCS_VARS=	BUILD_DEPENDS+=sphinx-build:textproc/py-sphinx

PATCH_STRIP=	-p1
CFLAGS+=	-D__BSD_VISIBLE=1
LDFLAGS+=	-pthread

OPTIONS_DEFINE=	CRYPTOPROFILE DOCS RDTSCP SASL SNAPPY SSL
OPTIONS_DEFAULT=	SSL
OPTIONS_SUB=	yes
CRYPTOPROFILE_DESC=	Use system crypto profile (require OPENSSL)
RDTSCP_DESC=	Fast performance counters on Intel using the RDTSCP instruction
SSL_DESC=	Enable TLS connections and SCRAM-SHA-1 authentication
SSL_USES=	ssl
SSL_CMAKE_OFF=	-DENABLE_SSL=OFF
CRYPTOPROFILE_IMPLIES=	SSL

CMAKE_ON=	ENABLE_EXAMPLES
CMAKE_OFF=	ENABLE_TESTS ENABLE_UNINSTALL
CMAKE_ARGS=	-DENABLE_MONGOC=ON -DENABLE_BSON=SYSTEM
CMAKE_ARGS+=	-DENABLE_ZLIB=SYSTEM -DENABLE_ZSTD=ON
CMAKE_ARGS+=	-DBSON_HAVE_STRINGS_H=0
DOCS_CMAKE_ON=	-DENABLE_HTML_DOCS=ON -DENABLE_MAN_PAGES=ON
RDTSCP_CMAKE_ON=	-DENABLE_RDTSCP=ON
RDTSCP_CMAKE_OFF=	-DENABLE_RDTSCP=OFF
SASL_CMAKE_ON=	-DENABLE_SASL=CYRUS
SASL_CMAKE_OFF=	-DENABLE_SASL=OFF
SNAPPY_CMAKE_ON=	-DENABLE_SNAPPY=ON
SNAPPY_CMAKE_OFF=	-DENABLE_SNAPPY=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
.	if ${SSL_DEFAULT:Mlibressl*}
CMAKE_ARGS+=	-DENABLE_SSL=LIBRESSL
.	else
CMAKE_ARGS+=	-DENABLE_SSL=OPENSSL
.	endif
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1300523
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_libmongoc_src_mongoc_mongoc-counters-private.h
.endif

pre-configure-CRYPTOPROFILE-on:
.if ${SSL_DEFAULT:Mlibressl*}
	@${ECHO_MSG} "CRYPTOPROFILE requires OpenSSL."
	@${FALSE}
.endif

post-extract:
	${ECHO} "${PORTVERSION}" > ${WRKSRC}/VERSION_CURRENT

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mongoc-stat

.include <bsd.port.mk>
