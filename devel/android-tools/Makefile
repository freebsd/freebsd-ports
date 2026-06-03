PORTNAME=	android-tools
PORTVERSION=	35.0.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/nmeum/android-tools/releases/download/${PORTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Android debugging tools
WWW=		https://github.com/nmeum/android-tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		libfmt.so:devel/libfmt \
		liblz4.so:archivers/liblz4 \
		libpcre2-8.so:devel/pcre2 \
		libprotobuf.so:devel/protobuf \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++20-lang localbase:ldflags pkgconfig python shebangfix tar:xz

SHEBANG_FILES=	vendor/avb/avbtool.py \
		vendor/libufdt/utils/src/mkdtboimg.py \
		vendor/mkbootimg/mkbootimg.py \
		vendor/mkbootimg/repack_bootimg.py \
		vendor/mkbootimg/unpack_bootimg.py

CMAKE_ARGS=	-DANDROID_TOOLS_PATCH_VENDOR:BOOL=OFF

.include <bsd.port.mk>
