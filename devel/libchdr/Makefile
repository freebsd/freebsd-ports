PORTNAME=	libchdr
DISTVERSION=	g20241111
CATEGORIES=	devel

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Standalone library for reading MAME CHDv1-v5 formats
WWW=		https://github.com/rtissera/libchdr

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rtissera
GH_TAGNAME=	b3974651d869c2f804e9879b063c23280d2ae617
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_LTO=${defined(WITH_LTO):?ON:OFF}
CMAKE_ON=	INSTALL_STATIC_LIBS WITH_SYSTEM_ZLIB WITH_SYSTEM_ZSTD

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libchdr-static.a ${STAGEDIR}${PREFIX}/lib/libchdr.a

.include <bsd.port.mk>
