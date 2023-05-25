PORTNAME=	vbz-compression
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	archivers

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Variable byte integer encoding to compress Oxford Nanopore signal data
WWW=		https://github.com/nanoporetech/vbz_compression

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

BUILD_DEPENDS=	streamvbyte>=0.4.1:archivers/streamvbyte
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libzstd.so:archivers/zstd

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/hdf5/lib/plugin

GH_ACCOUNT=	nanoporetech
GH_PROJECT=	vbz_compression

CMAKE_ARGS=	-DENABLE_CONAN=OFF \
		-DENABLE_PERF_TESTING=OFF \
		-DENABLE_PYTHON=OFF \
		-DSTREAMVBYTE_INSTALL_DIR=${LOCALBASE} \
		-DSTREAMVBYTE_STATIC_LIB=${LOCALBASE}/lib/libstreamvbyte.a

PLIST_FILES=	hdf5/lib/plugin/libvbz_hdf_plugin.so

.include <bsd.port.mk>
