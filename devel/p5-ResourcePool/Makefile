# ex:ts=8
# Ports collection makefile for:	p5-ResourcePool
# Date created:			Aug 9, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	ResourcePool
PORTVERSION=	1.0104
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	../by-authors/id/M/MW/MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A generic way to use connection caching for any kind of resources

PERL_CONFIGURE=	YES

MAN3=	ResourcePool.3 \
	ResourcePool::BigPicture.3 \
	ResourcePool::Command.3 \
	ResourcePool::Command::Exception.3 \
	ResourcePool::Command::Execute.3 \
	ResourcePool::Command::NoFailoverException.3 \
	ResourcePool::ExtensionGuide.3 \
	ResourcePool::Factory.3 \
	ResourcePool::LoadBalancer.3 \
	ResourcePool::Resource.3 \
	ResourcePool::Singleton.3 \
	ResourcePool::UML.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
