PORTNAME=	stackprof
PORTVERSION=	0.2.26
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Fast sampling profiler for ruby code
WWW=		https://github.com/tmm1/stackprof

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem python shebangfix

SHEBANG_FILES=	vendor/gprof2dot/gprof2dot.py \
		vendor/gprof2dot/hotshotmain.py \
		vendor/FlameGraph/flamegraph.pl

PLIST_FILES=	bin/stackprof \
		bin/stackprof-flamegraph.pl \
		bin/stackprof-gprof2dot.py

.include <bsd.port.mk>
