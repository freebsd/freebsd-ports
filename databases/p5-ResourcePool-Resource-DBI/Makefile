# Created by: erwin@FreeBSD.org
# $FreeBSD$

PORTNAME=	ResourcePool-Resource-DBI
PORTVERSION=	1.0101
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	CPAN:MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	ResourcePool::Resource::DBI - A ResourcePool wrapper for DBI

BUILD_DEPENDS=	p5-ResourcePool>=0:${PORTSDIR}/devel/p5-ResourcePool \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		ResourcePool::Resource::DBI.3 ResourcePool::Factory::DBI.3 \
		ResourcePool::Command::DBI::Execute.3 ResourcePool::Command::DBI::Select.3 \
		ResourcePool::Command::DBI::SelectRow.3

.include <bsd.port.mk>
