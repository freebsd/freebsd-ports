PORTNAME=	radare2
DISTVERSION=	6.1.4
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files
WWW=		https://www.radare.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.md

NOT_FOR_ARCHS=	armv6 armv7 powerpcspe
NOT_FOR_ARCHS_REASON=	does not build: Unsupported BSD architecture

LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libzip.so:archivers/libzip

USES=		cpe localbase meson pathfix pkgconfig python shebangfix tar:xz
CPE_VENDOR=	radare
PATHFIX_MAKEFILEIN=	Makefile
USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_TUPLE=	\
		radareorg:sdb:2.4.2:sdb/subprojects/sdb \
		quickjs-ng:quickjs:e2b100e8c5fa7131e9fb22b8a0e9ca0f16eb9892:qjs/subprojects/qjs

SHEBANG_FILES=	sys/clang-format-radare2

MESON_ARGS=	-Duse_sys_zip=true \
		-Duse_sys_capstone=true

MAKE_ENV+=	HOST_CC=${CC}

CFLAGS+=	-I${PREFIX}/include/capstone

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
			MAJOR_VERSION="${PORTVERSION:R}"

OPTIONS_DEFINE=	DOCS

# libr/flag/d/Makefile generates an r2 script from all files in
# current directory, including .bak file left by ${REINPLACE_CMD}
# called by pathfix.
post-patch:
	${CP} ${WRKSRC}/libr/debug/p/native/linux/reg/linux-ppc.h \
		${WRKSRC}/libr/debug/p/native/reg/kfbsd-ppc.h
	${CP} ${WRKSRC}/libr/debug/p/native/linux/reg/linux-ppc64.h \
		${WRKSRC}/libr/debug/p/native/reg/kfbsd-ppc64.h
	${CP} ${WRKSRC}/libr/debug/p/native/linux/reg/linux-riscv64.h \
		${WRKSRC}/libr/debug/p/native/reg/kfbsd-riscv64.h
	${CP} ${WRKSRC}/subprojects/packagefiles/qjs/meson.build \
		${WRKSRC}/subprojects/qjs/meson.build
	${RM} ${WRKSRC}/libr/flag/d/Makefile.bak

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/doc -type f -d 1 -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR} \;

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/r2sdb
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsdb.so.*

.include <bsd.port.mk>
