# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flang-clang
DISTVERSION=	4.0-20170812
PORTREVISION=	1
CATEGORIES=	devel lang

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Fortran compiler targeting LLVM (modified clang part)

LICENSE=	LLVM
LICENSE_NAME=	LLVM Release License
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	llvm40>=0:devel/llvm40 \
		openmp>=0:devel/openmp
RUN_DEPENDS=	llvm40>=0:devel/llvm40 \
		openmp>=0:devel/openmp

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	for now only builds and is supported on amd64

USE_LDCONFIG=	${PREFIX}/flang/lib
USES=		cmake:outsource compiler:c++11-lib libedit tar:xz perl5 \
		python shebangfix

USE_GNOME+=	libxml2

SHEBANG_FILES=	tools/scan-view/bin/scan-view \
		tools/clang-format/git-clang-format \
		tools/clang-format/clang-format-diff.py

USE_GITHUB=	yes
GH_ACCOUNT=	flang-compiler
GH_PROJECT=	clang
GH_TAGNAME=	79d1970

CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config40

CMAKE_INSTALL_PREFIX=	${PREFIX}/flang

post-install:
	@${GZIP_CMD} ${STAGEDIR}/${PREFIX}/flang/man/man1/scan-build.1
.include <bsd.port.mk>
