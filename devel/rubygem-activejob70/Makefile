PORTNAME=	activejob
PORTVERSION=	7.0.2.4
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Job class declarations for a variety of queueing backends

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=${PORTVERSION}:devel/rubygem-activesupport70 \
		rubygem-globalid-rails70>=0.3.6:databases/rubygem-globalid-rails70

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_job

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
