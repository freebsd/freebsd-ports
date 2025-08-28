PORTNAME=	wasi-libc
DISTVERSIONPREFIX=	wasi-sdk-
DISTVERSION=	27
CATEGORIES=	devel
PKGNAMESUFFIX=	${FLAVOR}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	C standard library for WebAssembly System Interface
WWW=		https://github.com/WebAssembly/wasi-libc

LICENSE=	APACHE20 MIT LLVM2
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_LLVM2=	${WRKSRC}/LICENSE-APACHE-LLVM
LICENSE_NAME_LLVM2=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS_LLVM2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash

FLAVORS=	19 20 21 18 17
FLAVOR?=	${FLAVORS:[1]}

USES=		gmake llvm:${FLAVOR}
USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
GH_TUPLE=	WebAssembly:WASI:59cbe14:wasi/tools/wasi-headers/WASI
NO_ARCH=	yes
PLIST=		${PKGDIR}/pkg-plist${LLVM_VERSION}
CONFLICTS_INSTALL=	wasi-libc[0-9]*

ALL_TARGET=	finish

# NOTE: matches the https://github.com/WebAssembly/wasi-sdk
WASI_SYSROOT=	${PREFIX}/share/wasi-sysroot

MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${WASI_SYSROOT} \
		EXTRA_CFLAGS="-O2 -DNDEBUG -isystem ${FILESDIR}" \
		AR=${LOCALBASE}/bin/llvm-ar${LLVM_VERSION} \
		NM=${LOCALBASE}/bin/llvm-nm${LLVM_VERSION} \

post-patch:
# NOTE: phony targets cause make install to rebuild everything
#       https://github.com/WebAssembly/wasi-libc/issues/156
	${REINPLACE_CMD} -e 's|install: finish|install:|' ${WRKSRC}/Makefile

post-install:
# NOTE: our llvm ports don't ship stdarg/stddef clang headers, so
#       they are copied from clang/lib/Headers into FILESDIR and we install
#       them to the sysroot
	${INSTALL_DATA} ${FILESDIR}/llvm${LLVM_VERSION}/*stdarg*.h ${STAGEDIR}${WASI_SYSROOT}/include/
	${INSTALL_DATA} ${FILESDIR}/llvm${LLVM_VERSION}/*stddef*.h ${STAGEDIR}${WASI_SYSROOT}/include/

.include <bsd.port.mk>
