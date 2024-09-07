PORTNAME=	derailed_benchmarks
PORTVERSION=	2.1.2
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Benchmarks for your whole Rails app
WWW=		https://github.com/schneems/derailed_benchmarks

LICENSE=	MIT

RUN_DEPENDS=	rubygem-benchmark-ips>=2.0.0<3:benchmarks/rubygem-benchmark-ips \
		rubygem-dead_end>=0:devel/rubygem-dead_end \
		rubygem-get_process_mem0>=0<1:devel/rubygem-get_process_mem0 \
		rubygem-heapy>=0<1:devel/rubygem-heapy \
		rubygem-memory_profiler>=0<2:devel/rubygem-memory_profiler \
		rubygem-mini_histogram>=0.3.0:devel/rubygem-mini_histogram\
		rubygem-rack>=1:www/rubygem-rack \
		rubygem-rake>=10<14:devel/rubygem-rake \
		rubygem-ruby-statistics>=2.1:devel/rubygem-ruby-statistics \
		rubygem-thor>=0.19<2:devel/rubygem-thor

USES=		gem

CONFLICTS_INSTALL=	rubygem-gitlab-derailed_benchmarks

NO_ARCH=	yes

PLIST_FILES=	bin/derailed

.include <bsd.port.mk>
