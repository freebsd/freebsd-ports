# ex:ts=8
# Ports collection makefile for:	p5-ResourcePool
# Date created:			Aug 9, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	ResourcePool
PORTVERSION=	0.9909
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	../by-authors/id/M/MW/MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	ResourcePool.3 \
	ResourcePool::BigPicture.3 \
	ResourcePool::ExtensionGuide.3 \
	ResourcePool::Factory.3 \
	ResourcePool::Factory::DBI.3 \
	ResourcePool::Factory::Net::LDAP.3 \
	ResourcePool::LoadBalancer.3 \
	ResourcePool::Resource.3 \
	ResourcePool::Resource::DBI.3 \
	ResourcePool::Resource::Net::LDAP.3 \
	ResourcePool::Singleton.3 \
	ResourcePool::UML.3

.include <bsd.port.mk>
