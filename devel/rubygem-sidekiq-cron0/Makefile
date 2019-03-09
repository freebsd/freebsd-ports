# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq-cron
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enables to set jobs to be run in specified time (using CRON notation)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Use devel/rubygem-sidekiq-cron instead
EXPIRATION_DATE=2019-03-31

RUN_DEPENDS=	rubygem-rufus-scheduler>=3.3.0:devel/rubygem-rufus-scheduler \
		rubygem-sidekiq>=4.2.1:devel/rubygem-sidekiq

PORTSCOUT=	limit:^0\.6\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
