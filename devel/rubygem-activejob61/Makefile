# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>

PORTNAME=	activejob
PORTVERSION=	6.1.4.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Job class declarations for a variety of queueing backends

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport61>=${PORTVERSION}:devel/rubygem-activesupport61 \
		rubygem-globalid-rails61>=0.3.6:databases/rubygem-globalid-rails61

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_job

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
