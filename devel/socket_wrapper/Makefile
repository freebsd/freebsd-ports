# $FreeBSD$

PORTNAME=		socket_wrapper
PORTVERSION=		1.1.9
CATEGORIES=		devel
MASTER_SITES=		SAMBA/cwrap

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Library passing all socket communications through unix sockets

LICENSE=		GPLv3

BROKEN_aarch64=		fails to compile: socket_wrapper.c:4036:9: cast to 'void *' from smaller integer type 'uintptr_t' (aka 'unsigned int')

USES=			cmake
USE_LDCONFIG=		yes

CFLAGS_mips=	-Wno-error=int-to-pointer-cast -Wno-error=pointer-to-int-cast
CFLAGS_mips64=	-Wno-error=int-to-pointer-cast -Wno-error=pointer-to-int-cast
CFLAGS_powerpcspe=	-Wno-error=int-to-pointer-cast -Wno-error=pointer-to-int-cast
CFLAGS_powerpc=	-Wno-error=int-to-pointer-cast -Wno-error=pointer-to-int-cast
CFLAGS_powerpc64=	-Wno-error=int-to-pointer-cast -Wno-error=pointer-to-int-cast
CFLAGS_sparc64=	-Wno-error=int-to-pointer-cast -Wno-error=pointer-to-int-cast
CMAKE_ARGS=		-DMAN_INSTALL_DIR:PATH="${PREFIX}/man"

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	UNIT_TESTING
TEST_BUILD_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

PLIST_FILES=		libdata/pkgconfig/socket_wrapper.pc \
			lib/cmake/socket_wrapper/socket_wrapper-config-version.cmake \
			lib/cmake/socket_wrapper/socket_wrapper-config.cmake \
			lib/libsocket_wrapper.so.0.1.9 \
			lib/libsocket_wrapper.so.0 \
			lib/libsocket_wrapper.so \
			man/man1/socket_wrapper.1.gz

post-configure:
			${REINPLACE_CMD} -Ee '/HAVE_FALLTHROUGH_ATTRIBUTE/d' \
			${CONFIGURE_WRKSRC}/config.h

.include <bsd.port.mk>
