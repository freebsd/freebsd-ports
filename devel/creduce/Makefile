PORTNAME=	creduce
DISTVERSIONPREFIX=	creduce-
DISTVERSION=	2.10.0-110
DISTVERSIONSUFFIX=	-g31e855e
PORTEPOCH=	2
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Produces small test cases
WWW=		https://github.com/csmith-project/creduce

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libzstd.so:archivers/zstd
RUN_DEPENDS=	topformflat:devel/delta \
		p5-Benchmark-Timer>=0:devel/p5-Benchmark-Timer \
		p5-Exporter-Lite>=0:devel/p5-Exporter-Lite \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Sys-CPU>=0:devel/p5-Sys-CPU \
		p5-Getopt-Tabular>=0:devel/p5-Getopt-Tabular \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

USES=		cmake gnome llvm:18,build,lib,run perl5

USE_GITHUB=	yes
GH_ACCOUNT=	csmith-project
USE_GNOME=	libxml2

# See clang_delta/CMakeLists.txt for more details
LDFLAGS+=	-lLLVM-${LLVM_VERSION} -L${LLVM_PREFIX}/lib

CMAKE_OFF=	ENABLE_TRANS_ASSERT
CMAKE_ARGS=	-DLLVM_DIR=${LLVM_PREFIX}/lib/cmake/llvm \
		-DClang_DIR=${LLVM_PREFIX}/lib/cmake/clang

.include <bsd.port.mk>
