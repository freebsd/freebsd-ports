PORTNAME=	activejob
PORTVERSION=	7.1.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Declare job classes that can be run by a variety of queuing backends
WWW=		https://github.com/rails/rails/tree/main/activejob \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport71 \
		rubygem-globalid-rails71>=0.3.6:databases/rubygem-globalid-rails71

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_job

PORTSCOUT=	limit:^7\.1\.

.include <bsd.port.mk>
