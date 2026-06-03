PORTNAME=	ladybug
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.1
CATEGORIES=	databases

MAINTAINER=	mahlon@martini.nu
COMMENT=	Embeddable, scalable, extremely fast graph database
WWW=		https://ladybugdb.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		libbrotlidec.so:archivers/brotli \
		liblz4.so:archivers/liblz4 \
		libyyjson.so:devel/yyjson \
		libzstd.so:archivers/zstd

USES=		cmake ninja:build python:build
USE_GITHUB=	yes
GH_ACCOUNT=	ladybugdb
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

EXTRACT_AFTER_ARGS=	--exclude third_party/brotli \
			--exclude third_party/lz4 \
			--exclude third_party/spdlog \
			--exclude third_party/yyjson \
			--exclude third_party/zstd \
			--no-same-owner --no-same-permissions

PLIST_SUB=	VERSION=${DISTVERSION}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/include/cppjieba ${STAGEDIR}${PREFIX}/share/cppjieba
	${MV}  ${STAGEDIR}${PREFIX}/lib/liblbug.so ${STAGEDIR}${PREFIX}/lib/liblbug.so.${DISTVERSION}
	${RLN} liblbug.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/liblbug.so
	${RLN} liblbug.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/liblbug.so.0

.include <bsd.port.mk>
