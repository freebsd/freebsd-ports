# Ports collection makefile for:	rubygem-railsbench
# Date created:				02 April 2007
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	railsbench
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	RF

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Scripts designed for benchmarking of Rails applications

BUILD_DEPENDS=	rubygem-hoe>=1.2.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/railsbench

OPTIONS=	GRUFF	"Plotting of perf data support using gruff"	off
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

.include <bsd.port.pre.mk>

.if defined(WITH_GRUFF)
RUN_DEPENDS+=	rubygem-gruff>=0.2.8:${PORTSDIR}/graphics/rubygem-gruff
.endif

.include <bsd.port.post.mk>
