# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	dm-devise
PORTVERSION=	2.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Adds DataMapper support to devise

RUN_DEPENDS=	rubygem-devise>=1.3:${PORTSDIR}/devel/rubygem-devise \
		rubygem-dm-core>=1.0.2:${PORTSDIR}/databases/rubygem-dm-core \
		rubygem-dm-migrations>=1.0.2:${PORTSDIR}/databases/rubygem-dm-migrations \
		rubygem-dm-rails>=1.0.3:${PORTSDIR}/databases/rubygem-dm-rails \
		rubygem-dm-serializer>=1.0.2:${PORTSDIR}/databases/rubygem-dm-serializer \
		rubygem-dm-timestamps>=1.0.2:${PORTSDIR}/databases/rubygem-dm-timestamps

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
