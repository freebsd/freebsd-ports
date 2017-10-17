# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	activejob
PORTVERSION=	5.0.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Job class declarations for a variety of queueing backends

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport50>=${PORTVERSION}:devel/rubygem-activesupport50 \
		rubygem-globalid-rails50>=0.3.6:databases/rubygem-globalid-rails50

PORTSCOUT=	limit:^5\.0\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
