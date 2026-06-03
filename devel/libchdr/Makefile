PORTNAME=	libchdr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
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

USE_LDCONFIG=	yes

CMAKE_ON=	INSTALL_STATIC_LIBS \
		WITH_SYSTEM_ZLIB \
		WITH_SYSTEM_ZSTD

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/deps/miniz* \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/deps/zstd* \
			--no-same-owner --no-same-permissions

PLIST_SUB=	SOVERSION=${DISTVERSION:R}

OPTIONS_DEFINE=		LTO
OPTIONS_DEFAULT=	LTO

LTO_CMAKE_BOOL=	BUILD_LTO

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libchdr-static.a ${STAGEDIR}${PREFIX}/lib/libchdr.a

.include <bsd.port.mk>
