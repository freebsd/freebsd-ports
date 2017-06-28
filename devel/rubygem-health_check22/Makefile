# Created by: Torsten Zuehlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	health_check
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple health check of Rails app for uptime monitoring

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

DEPRECATED=	Only created for www/gitlab; please use devel/rubygem-health_check instead
EXPIRATION_DATE=	2017-07-31

PORTSCOUT=	limit:^2\.2\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	test/setup_railsapp test/test_with_railsapp

.include <bsd.port.mk>
