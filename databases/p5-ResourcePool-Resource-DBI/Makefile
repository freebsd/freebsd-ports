# New ports collection makefile for:	p5-ResourcePool-Resource-DBI
# Date created:			February 06th, 2003
# Whom:	      			erwin@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ResourcePool-Resource-DBI
PORTVERSION=	1.0101
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	../by-authors/id/M/MW/MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	ResourcePool::Resource::DBI - A ResourcePool wrapper for DBI

BUILD_DEPENDS=	${SITE_PERL}/ResourcePool.pm:${PORTSDIR}/devel/p5-ResourcePool
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ResourcePool::Resource::DBI.3 ResourcePool::Factory::DBI.3 \
		ResourcePool::Command::DBI::Execute.3 ResourcePool::Command::DBI::Select.3 \
		ResourcePool::Command::DBI::SelectRow.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
