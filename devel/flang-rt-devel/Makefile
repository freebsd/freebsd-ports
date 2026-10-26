PORTREVISION=	0

LLVM_COMPONENT=	flang-rt
LLVM_VERDIR=	${.CURDIR}/../../devel/llvm-devel

NOT_FOR_ARCHS=	aarch64 armv6 armv7 i386 powerpc

.include "${.CURDIR}/../../devel/llvm/Makefile.component"

.if ${ARCH:Mpowerpc64*}
PLIST_FILES+=	${CLANG_RESOURCE_SUBDIR}/finclude/flang/${CONFIGURE_TARGET}/__ppc_intrinsics.mod \
		${CLANG_RESOURCE_SUBDIR}/finclude/flang/${CONFIGURE_TARGET}/__ppc_types.mod \
		${CLANG_RESOURCE_SUBDIR}/finclude/flang/${CONFIGURE_TARGET}/mma.mod
.endif

.include <bsd.port.mk>
