# New ports collection makefile for:	rubygem-datamapper
# Date created:		28, Dec 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	datamapper
PORTVERSION=	0.3.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, thread-safe, object-relational mapper

RUN_DEPENDS=	rubygem-rspec>0:${PORTSDIR}/devel/rubygem-rspec \
		rubygem-validatable>0:${PORTSDIR}/devel/rubygem-validatable \
		rubygem-json>0:${PORTSDIR}/devel/rubygem-json \
		rubygem-fastthread>0:${PORTSDIR}/devel/rubygem-fastthread

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
