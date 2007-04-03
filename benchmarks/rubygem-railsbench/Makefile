# Ports collection makefile for:	rubygem-railsbench
# Date created:				02 April 2007
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	railsbench
PORTVERSION=	0.9.2
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@logvinov.com
COMMENT=	Scripts designed for benchmarking of Rails applications

BUILD_DEPENDS=	rubygem-hoe>=1.2.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
