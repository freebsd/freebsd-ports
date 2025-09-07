PORTNAME=	activejob
PORTVERSION=	8.0.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Declare job classes that can be run by a variety of queuing backends
WWW=		https://github.com/rails/rails/tree/main/activejob \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport80 \
		rubygem-globalid-rails80>=0.3.6:databases/rubygem-globalid-rails80

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_job

PORTSCOUT=	limit:^8\.0\.

.include <bsd.port.mk>
