# $FreeBSD$

PORTNAME=	creduce
DISTVERSION=	2.9.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/creduce/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Produces small test cases

BUILD_DEPENDS=	llvm-config70:devel/llvm70
RUN_DEPENDS=	llvm-config70:devel/llvm70 \
		topformflat:devel/delta \
		astyle:devel/astyle \
		p5-Benchmark-Timer>=0:devel/p5-Benchmark-Timer \
		p5-Exporter-Lite>=0:devel/p5-Exporter-Lite \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Sys-CPU>=0:devel/p5-Sys-CPU \
		p5-Getopt-Tabular>=0:devel/p5-Getopt-Tabular

BROKEN_powerpc64=	fails to configure: cannot compile and link test program with selected LLVM

GNU_CONFIGURE=	yes
CONFIGURE_FLAGS=	--with-llvm=${LOCALBASE}
CONFIGURE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config70 \
		CC=${LOCALBASE}/bin/clang70 \
		CXX=${LOCALBASE}/bin/clang++70 \
		CPP=${LOCALBASE}/bin/clang-cpp70

USES=		autoreconf gmake libtool perl5

.include <bsd.port.mk>
