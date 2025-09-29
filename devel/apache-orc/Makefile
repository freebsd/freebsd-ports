PORTNAME=	orc
DISTVERSION=	2.2.0
CATEGORIES=	devel
MASTER_SITES=	https://dlcdn.apache.org/orc/orc-2.2.0/:orc \
		https://archive.apache.org/dist/orc/orc-format-1.1.0/:orc_format
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${DISTVERSION}.tar.gz:orc \
		orc-format-1.1.0.tar.gz:orc_format

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Smallest, fastest columnar storage for Hadoop workloads
WWW=		https://orc.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libgtest.so:devel/googletest \
		${LOCALBASE}/lib/libzstd.so:archivers/zstd
LIB_DEPENDS=	libsnappy.so:archivers/snappy \
		liblz4.so:archivers/liblz4 \
		libprotobuf.so:devel/protobuf \
		libabsl_demangle_internal.so:devel/abseil

USES=		cmake

CMAKE_ARGS+=	-DBUILD_JAVA=OFF \
		-DZLIB_HOME="/usr" \
		-DSNAPPY_HOME=${LOCALBASE} \
		-DLZ4_HOME=${LOCALBASE} \
		-DGTEST_HOME=${LOCALBASE} \
		-DPROTOBUF_HOME=${LOCALBASE} \
		-DZSTD_HOME=${LOCALBASE}
CFLAGS+=	-fPIC -Wno-error=unused-parameter
CPPFLAGS+=	-fPIC

post-patch:
		@${REINPLACE_CMD} "s#%%MYSITE%%#${DISTDIR}#g" \
			${WRKSRC}/cmake_modules/ThirdpartyToolchain.cmake

.include <bsd.port.mk>
