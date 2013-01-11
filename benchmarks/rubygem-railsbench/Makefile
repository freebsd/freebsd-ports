# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	railsbench
PORTVERSION=	0.9.8
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Scripts designed for benchmarking of Rails applications

RUN_DEPENDS=	rubygem-hoe>=1.2.0:${PORTSDIR}/devel/rubygem-hoe

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/railsbench

OPTIONS_DEFINE=	GRUFF
GRUFF_DESC=	Plotting of perf data support using gruff
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGRUFF}
RUN_DEPENDS+=	rubygem-gruff>=0.2.8:${PORTSDIR}/graphics/rubygem-gruff
.endif

.include <bsd.port.mk>
