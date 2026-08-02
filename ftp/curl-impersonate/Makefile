PORTNAME=	curl-impersonate
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	ftp
MASTER_SITES=	https://github.com/google/boringssl/archive/:boringssl \
		https://github.com/google/brotli/archive/refs/tags/:brotli \
		https://github.com/curl/curl/archive/:curl \
		https://github.com/nghttp2/nghttp2/releases/download/v1.63.0/:nghttp2 \
		https://github.com/ngtcp2/ngtcp2/releases/download/v1.20.0/:ngtcp2 \
		https://github.com/ngtcp2/nghttp3/releases/download/v1.15.0/:nghttp3 \
		https://github.com/madler/zlib/releases/download/v1.3.1/:zlib \
		https://github.com/facebook/zstd/releases/download/v1.5.7/:zstd
DISTFILES=	${BORING_SSL_COMMIT}.zip:boringssl \
		curl-8_21_0.tar.gz:curl \
		v1.2.0.tar.gz:brotli \
		nghttp2-1.63.0.tar.bz2:nghttp2 \
		ngtcp2-1.20.0.tar.bz2:ngtcp2 \
		nghttp3-1.15.0.tar.bz2:nghttp3 \
		zlib-1.3.1.tar.gz:zlib \
		zstd-1.5.7.tar.gz:zstd
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Curl with impersonation
WWW=		https://curl-impersonate.readthedocs.io/en/latest/ \
		https://github.com/lexiforest/curl-impersonate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake localbase:ldflags pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	lexiforest

BORING_SSL_COMMIT=	156c7b75ae9b8c3b3f847acf264f17594c3859fb

USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${RLN} ${DISTDIR}/${DIST_SUBDIR}/${BORING_SSL_COMMIT}.zip ${WRKSRC}/${BORING_SSL_COMMIT}.zip
	@${RLN} ${DISTDIR}/${DIST_SUBDIR}/v1.2.0.tar.gz ${WRKSRC}/brotli-1.2.0.tar.gz
	@${RLN} ${DISTDIR}/${DIST_SUBDIR}/curl-8_21_0.tar.gz ${WRKSRC}/curl-8_21_0.tar.gz
	@${RLN} ${DISTDIR}/${DIST_SUBDIR}/nghttp2-1.63.0.tar.bz2 ${WRKSRC}/nghttp2-1.63.0.tar.bz2
	@${RLN} ${DISTDIR}/${DIST_SUBDIR}/ngtcp2-1.20.0.tar.bz2 ${WRKSRC}/ngtcp2-1.20.0.tar.bz2
	@${RLN} ${DISTDIR}/${DIST_SUBDIR}/nghttp3-1.15.0.tar.bz2 ${WRKSRC}/nghttp3-1.15.0.tar.bz2
	@${RLN} ${DISTDIR}/${DIST_SUBDIR}/zlib-1.3.1.tar.gz ${WRKSRC}/zlib-1.3.1.tar.gz
	@${RLN} ${DISTDIR}/${DIST_SUBDIR}/zstd-1.5.7.tar.gz ${WRKSRC}/zstd-1.5.7.tar.gz

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|https://github.com/madler/zlib/releases/download/v$${ZLIB_VERSION}/zlib-$${ZLIB_VERSION}.tar.gz|file://$${CMAKE_SOURCE_DIR}/zlib-$${ZLIB_VERSION}.tar.gz|' \
		-e 's|https://github.com/facebook/zstd/releases/download/v$${ZSTD_VERSION}/zstd-$${ZSTD_VERSION}.tar.gz|file://$${CMAKE_SOURCE_DIR}/zstd-$${ZSTD_VERSION}.tar.gz|' \
		-e 's|https://github.com/google/brotli/archive/refs/tags/v$${BROTLI_VERSION}.tar.gz|file://$${CMAKE_SOURCE_DIR}/brotli-$${BROTLI_VERSION}.tar.gz|' \
		-e 's|https://github.com/google/boringssl/archive/$${BORINGSSL_COMMIT}.zip|file://$${CMAKE_SOURCE_DIR}/$${BORINGSSL_COMMIT}.zip|' \
		-e 's|https://github.com/nghttp2/nghttp2/releases/download/v$${NGHTTP2_VERSION}/nghttp2-$${NGHTTP2_VERSION}.tar.bz2|file://$${CMAKE_SOURCE_DIR}/nghttp2-$${NGHTTP2_VERSION}.tar.bz2|' \
		-e 's|https://github.com/ngtcp2/ngtcp2/releases/download/v$${NGTCP2_VERSION}/ngtcp2-$${NGTCP2_VERSION}.tar.bz2|file://$${CMAKE_SOURCE_DIR}/ngtcp2-$${NGTCP2_VERSION}.tar.bz2|' \
		-e 's|https://github.com/ngtcp2/nghttp3/releases/download/v$${NGHTTP3_VERSION}/nghttp3-$${NGHTTP3_VERSION}.tar.bz2|file://$${CMAKE_SOURCE_DIR}/nghttp3-$${NGHTTP3_VERSION}.tar.bz2|' \
		-e 's|https://github.com/curl/curl/archive/$${CURL_VERSION}.tar.gz|file://$${CMAKE_SOURCE_DIR}/$${CURL_VERSION}.tar.gz|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/CMakeFiles

.include <bsd.port.mk>
