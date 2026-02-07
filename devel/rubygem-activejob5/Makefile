PORTNAME=	activejob
PORTVERSION=	5.1.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Job class declarations for a variety of queueing backends
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/activejob

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport5>=${PORTVERSION}:devel/rubygem-activesupport5 \
		rubygem-globalid-rails5>=0.3.6:databases/rubygem-globalid-rails5

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_job

PORTSCOUT=	limit:^5\.1\.

.include <bsd.port.mk>
