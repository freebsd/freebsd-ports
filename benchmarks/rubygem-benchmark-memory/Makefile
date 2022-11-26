PORTNAME=	benchmark-memory
PORTVERSION=	0.2.0
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Benchmark-style memory profiling for Ruby 2.1+
WWW=		https://github.com/michaelherold/benchmark-memory

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-memory_profiler>=1<2:devel/rubygem-memory_profiler

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
