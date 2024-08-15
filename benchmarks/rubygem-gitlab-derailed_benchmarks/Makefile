PORTNAME=	gitlab-derailed_benchmarks
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Benchmarks for your whole Rails app
WWW=		https://github.com/schneems/derailed_benchmarks

LICENSE=	MIT

RUN_DEPENDS=	rubygem-benchmark-ips>=2.0.0:benchmarks/rubygem-benchmark-ips \
		rubygem-get_process_mem0>=0:devel/rubygem-get_process_mem0 \
		rubygem-heapy>=0:devel/rubygem-heapy \
		rubygem-memory_profiler>=0:devel/rubygem-memory_profiler \
		rubygem-rack>=1:www/rubygem-rack \
		rubygem-rake>=10<14:devel/rubygem-rake \
		rubygem-ruby-statistics>=2.1:devel/rubygem-ruby-statistics \
		rubygem-thor>=0.19:devel/rubygem-thor

USES=		gem

CONFLICTS_INSTALL=	rubygem-derailed_benchmarks

NO_ARCH=	yes

PLIST_FILES=	bin/derailed

.include <bsd.port.mk>
