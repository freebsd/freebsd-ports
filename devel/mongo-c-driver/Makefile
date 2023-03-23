PORTNAME=	mongo-c-driver
DISTVERSION=	1.23.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/mongodb/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ports@bsdserwis.com
COMMENT=	C Driver for MongoDB
WWW=		https://github.com/mongodb/mongo-c-driver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbson-1.0.so:devel/libbson \
		libzstd.so:archivers/zstd

USES=		cmake cpe pathfix pkgconfig python:env
CPE_VENDOR=	mongodb
USE_LDCONFIG=	yes

CFLAGS+=	-D__BSD_VISIBLE=1

CMAKE_OFF=	BUILD_TESTING \
		ENABLE_EXAMPLES \
		ENABLE_TESTS \
		ENABLE_UNINSTALL
CMAKE_ON=	ENABLE_MONGOC \
		ENABLE_ZSTD
CMAKE_ARGS=	-DENABLE_BSON=SYSTEM \
		-DENABLE_ZLIB=SYSTEM

OPTIONS_DEFINE=		CRYPTOPROFILE DOCS ICU RDTSCP SASL SNAPPY SSL
OPTIONS_DEFAULT=	SSL
OPTIONS_SUB=		yes

CRYPTOPROFILE_DESC=	Use system crypto profile (requires OpenSSL)
RDTSCP_DESC=		Fast performance counters on Intel using the RDTSCP instruction

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_CMAKE_ON=		-DENABLE_HTML_DOCS=ON -DENABLE_MAN_PAGES=ON

ICU_LIB_DEPENDS=	libicudata.so:devel/icu
ICU_CMAKE_ON=		-DENABLE_ICU=ON
ICU_CMAKE_OFF=		-DENABLE_ICU=OFF

RDTSCP_CMAKE_ON=	-DENABLE_RDTSCP=ON
RDTSCP_CMAKE_OFF=	-DENABLE_RDTSCP=OFF

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CMAKE_ON=		-DENABLE_SASL=CYRUS
SASL_CMAKE_OFF=		-DENABLE_SASL=OFF

SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
SNAPPY_CMAKE_ON=	-DENABLE_SNAPPY=ON
SNAPPY_CMAKE_OFF=	-DENABLE_SNAPPY=OFF

SSL_USES=		ssl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
.if	${SSL_DEFAULT:Mlibressl*}
CMAKE_ARGS+=	-DENABLE_SSL=LIBRESSL
.endif
CMAKE_ARGS+=	-DENABLE_SSL=OPENSSL
.else
CMAKE_ARGS+=	-DENABLE_SSL=OFF
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
	${ECHO} "${DISTVERSION}" > ${WRKSRC}/VERSION_CURRENT

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mongoc-stat

.include <bsd.port.mk>
