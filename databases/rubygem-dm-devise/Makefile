# Ports collection makefile for:	rubygem-dm-devise
# Date created:				2011-06-16
# Whom:					rpsfa@rit.edu
#
# $FreeBSD$

PORTNAME=	dm-devise
PORTVERSION=	1.4.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Adds DataMapper support to devise

RUN_DEPENDS=	rubygem-devise>=1.3.0:${PORTSDIR}/devel/rubygem-devise \
		rubygem-dm-core>=1.0.2:${PORTSDIR}/databases/rubygem-dm-core \
		rubygem-dm-migrations>=1.0.2:${PORTSDIR}/databases/rubygem-dm-migrations \
		rubygem-dm-rails>=1.0.3:${PORTSDIR}/databases/rubygem-dm-rails \
		rubygem-dm-serializer>=1.0.2:${PORTSDIR}/databases/rubygem-dm-serializer \
		rubygem-dm-timestamps>=1.0.2:${PORTSDIR}/databases/rubygem-dm-timestamps \
		rubygem-sugar-high>=0.2.10:${PORTSDIR}/devel/rubygem-sugar-high

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
