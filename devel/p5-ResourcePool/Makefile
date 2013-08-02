# Created by: ijliao
# $FreeBSD$

PORTNAME=	ResourcePool
PORTVERSION=	1.0107
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	CPAN:MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic way to use connection caching for any kind of resources

USES=		perl5
USE_PERL5=	configure

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
