# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq-cron
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enables to set jobs to be run in specified time (using CRON notation)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Use the same rubygem-sidekiq for www/gitlab-ce and its dependencies
RUN_DEPENDS=	rubygem-fugit>=1.1<2:devel/rubygem-fugit \
		rubygem-sidekiq5>=4.2.1:devel/rubygem-sidekiq5

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
