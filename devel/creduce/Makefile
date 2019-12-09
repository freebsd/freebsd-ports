# $FreeBSD$

PORTNAME=	creduce
DISTVERSION=	2.10.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/creduce/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Produces small test cases

LLVM_VER=	80
BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
RUN_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER} \
		topformflat:devel/delta \
		astyle:devel/astyle \
		p5-Benchmark-Timer>=0:devel/p5-Benchmark-Timer \
		p5-Exporter-Lite>=0:devel/p5-Exporter-Lite \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Sys-CPU>=0:devel/p5-Sys-CPU \
		p5-Getopt-Tabular>=0:devel/p5-Getopt-Tabular

BROKEN_FreeBSD_11_powerpc64=	fails to configure: cannot compile and link test program with selected LLVM
BROKEN_FreeBSD_12_powerpc64=	fails to configure: cannot compile and link test program with selected LLVM

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VER} \
		CC=${LOCALBASE}/bin/clang${LLVM_VER} \
		CXX=${LOCALBASE}/bin/clang++${LLVM_VER} \
		CPP=${LOCALBASE}/bin/clang-cpp${LLVM_VER}

USES=		autoreconf gmake libtool perl5

CFLAGS_powerpc64=	-mabi=elfv2

.include <bsd.port.mk>
