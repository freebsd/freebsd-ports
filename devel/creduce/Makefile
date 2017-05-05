# $FreeBSD$

PORTNAME=	creduce
DISTVERSION=	2.6.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/creduce/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Produces small test cases

BUILD_DEPENDS=	llvm-config39:devel/llvm39
RUN_DEPENDS=	llvm-config39:devel/llvm39 \
		topformflat:devel/delta \
		astyle:devel/astyle \
		p5-Benchmark-Timer>=0:devel/p5-Benchmark-Timer \
		p5-Exporter-Lite>=0:devel/p5-Exporter-Lite \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		devel/p5-Sys-Cpu>=0:devel/p5-Sys-Cpu \
		p5-Getopt-Tabular>=0:devel/p5-Getopt-Tabular

GNU_CONFIGURE=	yes
CONFIGURE_FLAGS=	--with-llvm=${LOCALBASE}
CONFIGURE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config39 \
		CC=${LOCALBASE}/bin/clang39 \
		CXX=${LOCALBASE}/bin/clang++39 \
		CPP=${LOCALBASE}/bin/clang-cpp39

USES=		autoreconf gmake libtool perl5

.include <bsd.port.mk>
