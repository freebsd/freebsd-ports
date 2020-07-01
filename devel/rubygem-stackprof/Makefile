# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stackprof
PORTVERSION=	0.2.15
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Fast sampling profiler for ruby code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem python shebangfix
USE_RUBY=	yes

SHEBANG_FILES=	vendor/gprof2dot/gprof2dot.py \
		vendor/gprof2dot/hotshotmain.py \
		vendor/FlameGraph/flamegraph.pl

PLIST_FILES=	bin/stackprof \
		bin/stackprof-flamegraph.pl \
		bin/stackprof-gprof2dot.py

.include <bsd.port.mk>
