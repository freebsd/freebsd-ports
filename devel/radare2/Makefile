PORTNAME=	radare2
DISTVERSION=	6.2.0
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files
WWW=		https://www.radare.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.md

NOT_FOR_ARCHS=	armv6 armv7 powerpcspe
NOT_FOR_ARCHS_REASON=	does not build: Unsupported BSD architecture

LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libxxhash.so:devel/xxhash \
		libzip.so:archivers/libzip

USES=		cpe compiler:c++23-lang localbase meson pathfix pkgconfig python shebangfix tar:xz
CPE_VENDOR=	radare
PATHFIX_MAKEFILEIN=	Makefile
USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_TUPLE=	\
		radareorg:sdb:2.5.0:sdb/subprojects/sdb \
		quickjs-ng:quickjs:9d15fb60b67c45fd0de413bb49e48f8dacebac16:qjs/subprojects/qjs \
		zyantific:zydis:v4.1.0:zydis/subprojects/zydis

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
	${CP} ${WRKSRC}/subprojects/packagefiles/zydis/meson.build \
		${WRKSRC}/subprojects/zydis/meson.build
	${CP} -R ${WRKSRC}/subprojects/packagefiles/zydis/amalgamated-dist \
		${WRKSRC}/subprojects/zydis/
	${RM} ${WRKSRC}/libr/flag/d/Makefile.bak

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/doc -type f -d 1 -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR} \;

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/r2sdb
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsdb.so.*

.include <bsd.port.mk>
