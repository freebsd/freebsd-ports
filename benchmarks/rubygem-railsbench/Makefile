# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	railsbench
PORTVERSION=	0.9.8
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Scripts designed for benchmarking of Rails applications

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-hoe>=2.4.0:${PORTSDIR}/devel/rubygem-hoe

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/railsbench

OPTIONS_DEFINE=	GRUFF
GRUFF_DESC=	Plotting of perf data support using gruff

GRUFF_RUN_DEPENDS=	rubygem-gruff>=0.2.8:${PORTSDIR}/graphics/rubygem-gruff

.include <bsd.port.mk>
