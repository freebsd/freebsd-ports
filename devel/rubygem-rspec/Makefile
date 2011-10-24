# Ports collection makefile for:	rubygem-rspec
# Date created:				22 December 2006
# Whom:					Roman Shterenzon <romanbsd@yahoo.com>
#
# $FreeBSD$

PORTNAME=	rspec
PORTVERSION=	2.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	romanbsd@yahoo.com
COMMENT=	Behaviour Driven Development in Ruby

BUILD_DEPENDS=	rubygem-rspec-core>=0:${PORTSDIR}/devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=0:${PORTSDIR}/devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=0:${PORTSDIR}/devel/rubygem-rspec-mocks
RUN_DEPENDS=	rubygem-rspec-core>=0:${PORTSDIR}/devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=0:${PORTSDIR}/devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=0:${PORTSDIR}/devel/rubygem-rspec-mocks

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
