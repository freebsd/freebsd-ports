# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	derailed_benchmarks
PORTVERSION=	1.3.6
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Benchmarks for your whole Rails app

LICENSE=	MIT

RUN_DEPENDS=	rubygem-benchmark-ips>=2.0.0:benchmarks/rubygem-benchmark-ips \
		rubygem-get_process_mem>=0:devel/rubygem-get_process_mem \
		rubygem-heapy>=0:devel/rubygem-heapy \
		rubygem-memory_profiler>=0:devel/rubygem-memory_profiler \
		rubygem-rack>=1:www/rubygem-rack \
		rubygem-rake>=10:devel/rubygem-rake \
		rubygem-thor>=0.19:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/derailed

.include <bsd.port.mk>
