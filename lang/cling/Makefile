# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME=		cling
DISTVERSION=		0.5-2018-08-13
PORTREVISION=		4
CATEGORIES=		lang devel
MASTER_SITES=		https://root.cern.ch/download/cling/
DISTNAME=		${PORTNAME}_${DISTVERSION:C/^[0-9]\.[0-9]-//}_sources

MAINTAINER=		mmokhi@FreeBSD.org
COMMENT=		Interactive C++ Interpreter Based on LLVM and Clang Libs

LICENSE=		LLVM NCSA
LICENSE_COMB=		multi
LICENSE_NAME_LLVM=	LLVM Release License
LICENSE_FILE_LLVM=	${WRKSRC}/LICENSE.TXT
LICENSE_FILE_NCSA=	${WRKSRC}/tools/cling/LICENSE.TXT
LICENSE_PERMS_LLVM=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_armv6=		fails to compile: AArch64TargetMachine.cpp: relocation truncated to fit: R_ARM_CALL against symbol '__aeabi_uldivmod'
BROKEN_armv7=		fails to compile: AArch64TargetMachine.cpp: relocation truncated to fit: R_ARM_CALL against symbol '__aeabi_uldivmod'
BROKEN_FreeBSD_12_powerpc64=	fails to build: src/include/llvm/ExecutionEngine/Orc/OrcRemoteTargetClient.h:722:26: could not convert '((llvm::orc::remote::OrcRemoteTargetClient<ChannelT>*)this)->callB<llvm::orc::remote::OrcRemoteTargetRPCAPI::ReadMem>(Src, Size)'

LIB_DEPENDS=	libgtest.so:devel/googletest \
		libz3.so:math/z3

WRKSRC=		${WRKDIR}/src

LLVM_RELEASE=	5.0.0
LLVM_SUFFIX=	50_cern-root
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}

USES=		cmake compiler:c++11-lib compiler:c11 cpe gnome libedit ncurses \
		python:build shebangfix tar:bzip2
USE_GNOME=	libxml2
USE_LDCONFIG=	${LLVM_PREFIX}/lib

SHEBANG_FILES=	tools/clang/tools/clang-format/clang-format-diff.py \
		tools/clang/tools/clang-format/git-clang-format \
		tools/clang/tools/scan-view/bin/scan-view

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	LLVM_BUILD_EXAMPLES LLVM_INCLUDE_TESTS LLVM_INCLUDE_GO_TESTS

SUB_LIST+=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"
PLIST_SUB+=		LLVM_SUFFIX=${LLVM_SUFFIX} LLVM_RELEASE=${LLVM_RELEASE}

CMAKE_BUILD_TYPE=	Release
CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}

CMAKE_ARGS+=	-DINSTALL_LAYOUT=FREEBSD \
	    --target ${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|g' \
	    ${PATCH_WRKSRC}/tools/cling/tools/driver/cling.cpp
	@${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|g' \
	    ${PATCH_WRKSRC}/tools/cling/lib/Interpreter/CIFactory.cpp

post-install:
	for e in $$(cd ${STAGEDIR}${PREFIX}/llvm50_cern-root/bin && ls *); do \
		${RLN} ${STAGEDIR}${PREFIX}/llvm50_cern-root/bin/$${e} ${STAGEDIR}${PREFIX}/bin/$${e}; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake
	for m in cling llvm llvm-c clang; do \
		${RLN} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/include/$${m} ${STAGEDIR}${PREFIX}/include/$${m}; \
	done
	for m in cling llvm clang; do \
		${RLN} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/lib/cmake/$${m} ${STAGEDIR}${PREFIX}/lib/cmake/$${m}; \
	done
	for l in $$(cd ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/lib && ls *.so* *.a); do \
		${RLN} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/lib/$${l} ${STAGEDIR}${PREFIX}/lib/$${l}; \
	done

.include <bsd.port.mk>
