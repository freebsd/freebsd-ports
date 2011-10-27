# Ports collection makefile for:	rubygem-devise
# Date created:				2011-06-16
# Whom:					rpsfa@rit.edu
#
# $FreeBSD$

PORTNAME=	devise
PORTVERSION=	1.4.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

RUN_DEPENDS=	rubygem-bcrypt-ruby>=3.0.1:${PORTSDIR}/security/rubygem-bcrypt-ruby \
		rubygem-warden>=1.0.3:${PORTSDIR}/devel/rubygem-warden \
		rubygem-orm_adapter>=0.0.3:${PORTSDIR}/devel/rubygem-orm_adapter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
