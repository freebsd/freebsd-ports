# $FreeBSD$

PORTNAME=	creduce
DISTVERSION=	2.4.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/creduce/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Produces small test cases

BUILD_DEPENDS=	llvm-config37:devel/llvm37
RUN_DEPENDS=	llvm-config37:devel/llvm37 \
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

USES=	gmake perl5

post-patch:
	${REINPLACE_CMD} 's,llvm-config,llvm-config37,g' ${WRKSRC}/configure

.include <bsd.port.mk>
