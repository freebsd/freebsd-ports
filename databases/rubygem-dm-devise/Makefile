# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	dm-devise
PORTVERSION=	2.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Adds DataMapper support to devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-devise>=1.3:devel/rubygem-devise \
		rubygem-dm-core>=1.0.2:databases/rubygem-dm-core \
		rubygem-dm-migrations>=1.0.2:databases/rubygem-dm-migrations \
		rubygem-dm-rails>=1.0.2:databases/rubygem-dm-rails \
		rubygem-dm-serializer>=1.0.2:databases/rubygem-dm-serializer \
		rubygem-dm-timestamps>=1.0.2:databases/rubygem-dm-timestamps

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
