# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>

PORTNAME=	activejob
PORTVERSION=	6.1.3.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Job class declarations for a variety of queueing backends

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport613>=${PORTVERSION}:devel/rubygem-activesupport613 \
		rubygem-globalid-rails61>=0.3.6:databases/rubygem-globalid-rails61

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	active_job

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
