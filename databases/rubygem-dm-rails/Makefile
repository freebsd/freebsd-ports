# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	dm-rails
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integrate DataMapper with Rails 3

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack>=3.0:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-dm-active_model>=1.2.0:${PORTSDIR}/databases/rubygem-dm-active_model \
		rubygem-dm-core>=1.2.0:${PORTSDIR}/databases/rubygem-dm-core \
		rubygem-railties>=3.0:${PORTSDIR}/www/rubygem-railties

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
