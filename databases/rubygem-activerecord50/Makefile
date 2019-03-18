# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	5.0.7.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel50>=${PORTVERSION}:databases/rubygem-activemodel50 \
		rubygem-activesupport50>=${PORTVERSION}:devel/rubygem-activesupport50 \
		rubygem-arel7>=7.0:databases/rubygem-arel7

PORTSCOUT=	limit:^5\.0\.

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
