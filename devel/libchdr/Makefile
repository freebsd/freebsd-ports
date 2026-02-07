PORTNAME=	libchdr
DISTVERSION=	g20250522
CATEGORIES=	devel

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Standalone library for reading MAME CHDv1-v5 formats
WWW=		https://github.com/rtissera/libchdr

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	rtissera
GH_TAGNAME=	40f96ee322971eedf2a16bdab6727daa861e8626
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_LTO=${defined(WITH_LTO):?ON:OFF}
CMAKE_ON=	INSTALL_STATIC_LIBS \
		WITH_SYSTEM_ZLIB \
		WITH_SYSTEM_ZSTD

EXTRACT_AFTER_ARGS=	--exclude deps/zlib* --exclude deps/zstd* \
			--no-same-owner --no-same-permissions

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libchdr-static.a ${STAGEDIR}${PREFIX}/lib/libchdr.a

.include <bsd.port.mk>
