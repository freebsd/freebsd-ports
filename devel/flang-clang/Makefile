# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flang-clang
DISTVERSION=	6.0-g20180904
PORTREVISION=	3
CATEGORIES=	devel lang

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Fortran compiler targeting LLVM (modified clang part)

LICENSE=	LLVM
LICENSE_NAME=	LLVM Release License
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	llvm60>=0:devel/llvm60
RUN_DEPENDS=	llvm60>=0:devel/llvm60

USES=		cmake compiler:c++11-lib libedit tar:xz perl5 \
		python shebangfix
USE_LDCONFIG=	${PREFIX}/flang/lib
USE_GNOME=	libxml2

SHEBANG_FILES=	tools/scan-view/bin/scan-view \
		tools/clang-format/git-clang-format \
		tools/clang-format/clang-format-diff.py

USE_GITHUB=	yes
GH_ACCOUNT=	flang-compiler
GH_PROJECT=	flang-driver
GH_TAGNAME=	742de5f

CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config60

CMAKE_INSTALL_PREFIX=	${PREFIX}/flang

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/lib/Driver/ToolChains/FreeBSD.cpp

post-install:
	@${GZIP_CMD} ${STAGEDIR}/${PREFIX}/flang/man/man1/scan-build.1
	${RLN} ${STAGEDIR}${PREFIX}/flang/bin/flang ${STAGEDIR}${PREFIX}/bin/flang

.include <bsd.port.mk>
