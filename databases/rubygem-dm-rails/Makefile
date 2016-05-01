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
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack>=3.0:www/rubygem-actionpack \
		rubygem-dm-active_model>=1.2.0:databases/rubygem-dm-active_model \
		rubygem-dm-core>=1.2.0:databases/rubygem-dm-core \
		rubygem-railties>=3.0:www/rubygem-railties

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
