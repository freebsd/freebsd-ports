# New ports collection makefile for:	rubygem-datamapper
# Date created:		28, Dec 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	datamapper
PORTVERSION=	0.3.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, thread-safe, object-relational mapper

BUILD_DEPENDS=	rubygem-rspec>0:${PORTSDIR}/devel/rubygem-rspec \
		rubygem-validatable>0:${PORTSDIR}/devel/rubygem-validatable \
		rubygem-json>0:${PORTSDIR}/devel/rubygem-json \
		rubygem-fastthread>0:${PORTSDIR}/devel/rubygem-fastthread
RUN_DEPENDS=	rubygem-rspec>0:${PORTSDIR}/devel/rubygem-rspec \
		rubygem-validatable>0:${PORTSDIR}/devel/rubygem-validatable \
		rubygem-json>0:${PORTSDIR}/devel/rubygem-json \
		rubygem-fastthread>0:${PORTSDIR}/devel/rubygem-fastthread

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
