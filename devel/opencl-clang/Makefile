PORTNAME=	opencl-clang
DISTVERSIONPREFIX=	v
DISTVERSION=	${DISTVERSION_${FLAVOR}}
DISTVERSION_llvm22=	22.1.0
DISTVERSION_llvm21=	21.1.2
DISTVERSION_llvm20=	20.1.2
DISTVERSION_llvm19=	19.1.2
DISTVERSION_llvm18=	18.1.3
DISTVERSION_llvm17=	17.0.3
DISTVERSION_llvm16=	16.0.8
DISTVERSION_llvm15=	15.0.6
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clang wrapper to compile OpenCL C kernels to SPIR-V modules
WWW=		https://github.com/intel/opencl-clang

USE_GITHUB=	yes
GH_ACCOUNT=	intel
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libLLVM-${LLVM_MJR}.so:devel/${FLAVOR} \
		libLLVMSPIRVLib.so.${SOVERSION}:devel/spirv-llvm-translator@${FLAVOR}

FLAVORS=	${22 21 20 19 18 17 16 15:L:S/^/llvm/}
FLAVOR?=	llvm${LLVM_DEFAULT}

LLVM_MJR=	${FLAVOR:S/llvm//}
PREFERRED_LLVM=	${DISTVERSION:R:S/.0$//}
LIB_DIRS+=	${LOCALBASE}/${FLAVOR}/lib
SOVERSION=	${${FLAVOR:S/llvm//}<18:?${DISTVERSION:R:R}:${DISTVERSION:R}}

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	${PREFIX}/${FLAVOR}/lib

.if ${LLVM_MJR} == 22
GH_TAGNAME=	aaa3866
.endif

.if ${LLVM_MJR} >= 15 && ${LLVM_MJR} <= 16
EXTRA_PATCHES+=	${PATCHDIR}/extra-15+16-patch-options.h
.elif ${LLVM_MJR} >= 17 && ${LLVM_MJR} <= 21
EXTRA_PATCHES+=	${PATCHDIR}/extra-17to21-patch-options.h
.endif

.if ${LLVM_MJR} <= 21
EXTRA_PATCHES+=	${PATCHDIR}/extra-15to21-patch-options__compile.cpp
.endif
.if ${LLVM_MJR} >= 16
EXTRA_PATCHES+=	${PATCHDIR}/extra-ge16-patch-common__clang.map
.endif

DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}
PLIST_FILES=	${_PLIST_FILES:S,^,${FLAVOR}/,}
CMAKE_ARGS=	-DCMAKE_PREFIX_PATH:PATH="${LOCALBASE}/${FLAVOR}" \
		-DPREFERRED_LLVM_VERSION:STRING="${PREFERRED_LLVM}"
CMAKE_INSTALL_PREFIX=		${PREFIX}/${FLAVOR}

_COMMONCLANG=		include/cclang/common_clang.h
_MODMODMP=		include/cclang/module.modulemap \
			include/cclang/opencl-c-base.h \
			include/cclang/opencl-c.h
.if ${LLVM_MJR} < 16
_PLIST_FILES+=	${_COMMONCLANG}
.else
_PLIST_FILES+=	include/cclang/opencl_clang.h
.endif

.if ${LLVM_MJR} != 13
_PLIST_FILES+=  ${_MODMODMP}
.endif

_PLIST_FILES+=	lib/libopencl-clang.so \
		lib/libopencl-clang.so.${PREFERRED_LLVM}

.include <bsd.port.pre.mk>

.if ${LLVM_MJR} < 19	# LLVM_DEFAULT
DEPRECATED=		Flavor ${FLAVOR} depends on obsolete LLVM version
EXPIRATION_DATE=	2026-12-25
.endif

.if !defined(DEFAULT_MAKESUM)
makesum:
. for f in ${FLAVORS}
	${MAKE} -C${.CURDIR} FLAVOR=$f DEFAULT_MAKESUM=1 ${.TARGET}
. endfor
.endif

.include <bsd.port.post.mk>
