# Created by: Johannes M Dieterich <jmd@FreeBSD.org>

PORTNAME=	flang-clang
DISTVERSION=	7.0-g20191020
PORTREVISION=	2
CATEGORIES=	devel lang

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Fortran compiler targeting LLVM (modified clang part)

LICENSE=	LLVM
LICENSE_NAME=	LLVM Release License
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Very outdated and unsupported upstream, current version in tree is several years old and upstream is still active
EXPIRATION_DATE=2022-09-30

ONLY_FOR_ARCHS=	amd64

LLVM_VER=	70
BUILD_DEPENDS=	llvm${LLVM_VER}>=0:devel/llvm${LLVM_VER}
RUN_DEPENDS=	llvm${LLVM_VER}>=0:devel/llvm${LLVM_VER}

USES=		cmake gnome libedit perl5 python shebangfix tar:xz
USE_LDCONFIG=	${PREFIX}/flang/lib
USE_GNOME=	libxml2

SHEBANG_FILES=	tools/scan-view/bin/scan-view \
		tools/clang-format/git-clang-format \
		tools/clang-format/clang-format-diff.py \
		utils/hmaptool/hmaptool

USE_GITHUB=	yes
GH_ACCOUNT=	flang-compiler
GH_PROJECT=	flang-driver
GH_TAGNAME=	984936a

CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VER} \
		-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_VER}/lib/cmake/llvm

CMAKE_INSTALL_PREFIX=	${PREFIX}/flang

CC=		${LOCALBASE}/llvm${LLVM_VER}/bin/clang
CXX=		${LOCALBASE}/llvm${LLVM_VER}/bin/clang++

# Support __builtin_is_constant_evaluated(), for libc++ >= 14
CXXFLAGS+=	-include ${FILESDIR}/builtin_is_constant_evaluated.h

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/lib/Driver/ToolChains/FreeBSD.cpp

post-install:
	@${GZIP_CMD} ${STAGEDIR}/${PREFIX}/flang/share/man/man1/scan-build.1
	${RLN} ${STAGEDIR}${PREFIX}/flang/bin/flang ${STAGEDIR}${PREFIX}/bin/flang

.include <bsd.port.mk>
