PORTNAME=	activejob
PORTVERSION=	5.0.7.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Job class declarations for a variety of queueing backends
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/activejob

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport50>=${PORTVERSION}:devel/rubygem-activesupport50 \
		rubygem-globalid-rails50>=0.3.6:databases/rubygem-globalid-rails50

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_job

PORTSCOUT=	limit:^5\.0\.

.include <bsd.port.mk>
