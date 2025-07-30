PORTNAME=	mold
DISTVERSIONPREFIX=	v
DISTVERSION=	2.40.3
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern Linker
WWW=		https://github.com/rui314/mold

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armhf armv7 i386

LIB_DEPENDS=	libmimalloc.so:devel/mimalloc \
		libtbb.so:devel/onetbb \
		libzstd.so:archivers/zstd
TEST_DEPENDS=	bash:shells/bash \
		gcc${GCC_DEFAULT}:lang/gcc${GCC_DEFAULT} \
		ggrep:textproc/gnugrep \
		${LOCALBASE}/bin/readelf:devel/binutils

USES=		cmake:testing compiler:c++20-lang localbase:ldflags shebangfix
SHEBANG_FILES=	test/*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	rui314

PLIST_FILES=	bin/ld.mold \
		bin/mold \
		lib/mold/mold-wrapper.so \
		libexec/mold/ld \
		share/man/man1/ld.mold.1.gz \
		share/man/man1/mold.1.gz


CMAKE_TESTING_OFF=	MOLD_ENABLE_QEMU_TESTS

CMAKE_ON=	MOLD_USE_MIMALLOC \
		MOLD_USE_SYSTEM_MIMALLOC \
		MOLD_USE_SYSTEM_TBB

CMAKE_OFF=	MOLD_USE_MOLD \
		MOLD_USE_TSAN \
		MOLD_MOSTLY_STATIC \
		BUILD_TESTING

OPTIONS_DEFINE=	ASAN LTO

ASAN_DESC=	Enable Address Sanitizer

ASAN_CMAKE_BOOL=MOLD_USE_ASAN

LTO_CMAKE_BOOL=	MOLD_LTO

pre-test:
	### BINARY_ALIAS doesn't work for tests so we need to fix it manually
	@${REINPLACE_CMD} -e 's|OBJCOPY=objcopy|OBJCOPY=${PREFIX}/bin/objcopy|g' \
	    ${PATCH_WRKSRC}/test/common.inc
	@${REINPLACE_CMD} -e 's|OBJDUMP=objdump|OBJDUMP=${PREFIX}/bin/objdump|g' \
	    ${PATCH_WRKSRC}/test/common.inc
	@${REINPLACE_CMD} -e 's|$$GCC |gcc${GCC_DEFAULT} |g' \
	    ${PATCH_WRKSRC}/test/*.sh
	@${REINPLACE_CMD} -e 's|gcc |gcc${GCC_DEFAULT} |g' \
	    ${PATCH_WRKSRC}/test/*.sh
	@${REINPLACE_CMD} -e 's|grep -|${PREFIX}/bin/ggrep -|g' \
	    ${PATCH_WRKSRC}/test/*.sh
	@${REINPLACE_CMD} -e 's|readelf |${PREFIX}/bin/readelf |g' \
	    ${PATCH_WRKSRC}/test/*.sh
	### Depends on LLVMgold plugin which isn't built by binutils
	@${RM} ${WRKSRC}/test/defsym-lto.sh
	@${RM} ${WRKSRC}/test/lto-archive.sh
	@${RM} ${WRKSRC}/test/lto-archive2.sh
	@${RM} ${WRKSRC}/test/lto-dso.sh
	@${RM} ${WRKSRC}/test/lto-version-script.sh
	@${RM} ${WRKSRC}/test/symbol-version-lto.sh
	### These tests errors out with "Unsupported relocation type 36 in non-PLT relocations"
	@${RM} ${WRKSRC}/test/tlsdesc.sh
	@${RM} ${WRKSRC}/test/tlsdesc-dlopen.sh
	@${RM} ${WRKSRC}/test/tlsdesc-initial-exec.sh
	@${RM} ${WRKSRC}/test/tlsdesc-local-dynamic.sh
	@${RM} ${WRKSRC}/test/wrap-lto.sh
	@${RM} ${WRKSRC}/test/x86_64_tlsdesc.sh
	@${RM} ${WRKSRC}/test/x86_64_tls-module-base.sh

.include <bsd.port.mk>
