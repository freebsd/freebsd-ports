# $FreeBSD$

PORTNAME=	compiler-rt
PORTVERSION=	${LLVM_MAJOR}.d${SNAPDATE}
CATEGORIES=	devel
PKGNAMESUFFIX=	${LLVM_SUFFIX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LLVM sanitizer runtimes

LLVM_SUFFIX=	-devel
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
LLVM_PORTDIR=	${.CURDIR}/../llvm${LLVM_SUFFIX}

USES=		cmake:outsource compiler:c++11-lib ninja

BUILD_DEPENDS=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX}

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}/
CMAKE_ARGS=	-DLLVM_CONFIG_PATH=${LOCALBASE}/bin/llvm-config${LLVM_SUFFIX}

USE_GITHUB=	eyes
GH_ACCOUNT=	llvm-mirror
GH_TAGNAME=	${COMPILER_RT_COMMIT}

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	plist contents not known

.include <bsd.port.pre.mk>

.for arch in ${ONLY_FOR_ARCHS}
_arch=${arch}
.if (${_arch} == ${ARCH} || (${_arch} == "i386" && ${ARCH} == "amd64" && ${COMPILER_TYPE} != "gcc"))
ARCH_SUB:=	${ARCH_SUB} ${arch:tu}=
.else
ARCH_SUB:=	${ARCH_SUB} ${arch:tu}="@comment "
.endif
.endfor
PLIST_SUB+=	${ARCH_SUB}

.include "${LLVM_PORTDIR}/Makefile.snapshot"

build-plist:
	${RM} -f ${PLIST}
	${MAKE} makeplist | \
	    grep -v /you/have/to/check/what/makeplist/gives/you | \
	    awk '{ \
		if ($$0 ~ /i386/) {printf "%%%%I386%%%%"} \
		if ($$0 ~ /x86_64/) {printf "%%%%AMD64%%%%"} \
		{print} \
	    }' >> ${PLIST}


.include <bsd.port.post.mk>
