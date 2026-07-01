PORTNAME=	minizip-ng
DISTVERSION=	4.2.2
CATEGORIES=	archivers

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Fork of the popular minizip found in the zlib distribution
WWW=		https://github.com/zlib-ng/minizip-ng

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libz-ng.so:archivers/zlib-ng \
		libzstd.so:archivers/zstd

USES=		cmake:testing cpe iconv pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	zlib-ng
# CMakeList.txt: clone_repo(ppmd https://github.com/ip7z/7zip "26.02")
7ZIP_VER=	26.02
GH_TUPLE=	ip7z:7zip:${7ZIP_VER}:7zip/third_party/ppmd
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=${LOCALBASE}/include \
		-DMZ_LIB_SUFFIX=-ng
CMAKE_ON=	BUILD_SHARED_LIBS \
		CMAKE_DISABLE_FIND_PACKAGE_ZLIB \
		CMAKE_POSITION_INDEPENDENT_CODE
CMAKE_TESTING_ON=	MZ_BUILD_TEST MZ_BUILD_UNIT_TEST

EXTRACT_AFTER_ARGS=	--exclude 7zip-${7ZIP_VER}/[ABD-Z]* \
			--exclude 7zip-${7ZIP_VER}/C/7z[A-SUW-Za-z.]* \
			--exclude 7zip-${7ZIP_VER}/C/7zVersion.rc \
			--exclude 7zip-${7ZIP_VER}/C/[ABD-OQ-Za-z]* \
			--exclude 7zip-${7ZIP_VER}/C/CpuArch.c \
			--exclude 7zip-${7ZIP_VER}/C/Ppmd7* \
			--exclude 7zip-${7ZIP_VER}/CPP \
			--no-same-owner --no-same-permissions

PLIST_SUB=	VERSION="${DISTVERSION}"

CPE_VENDOR=	zlib-ng

post-install:
	${INSTALL_DATA} ${FILESDIR}/mz_compat.h \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
