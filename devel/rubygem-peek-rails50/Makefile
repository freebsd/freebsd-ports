# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	peek
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Take a peek into your Rails application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS?=	rubygem-concurrent-ruby>=0.9.0:devel/rubygem-concurrent-ruby \
		rubygem-concurrent-ruby-ext>=0.9.0:devel/rubygem-concurrent-ruby-ext

OPTIONS_RADIO=	RAILS
OPTIONS_RADIO_RAILS=	RAILS4 RAILS5
OPTIONS_DEFAULT=RAILS50
RAILS4_DESC=	Use Rails 4
RAILS5_DESC=	Use Rails 5
RAILS50_DESC=	Use Rails 5.0

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

RAILS4_RUN_DEPENDS=	rubygem-railties4>=4.0.0:www/rubygem-railties4
RAILS5_RUN_DEPENDS=	rubygem-railties5>=4.0.0:www/rubygem-railties5
RAILS50_RUN_DEPENDS=	rubygem-railties50>=4.0.0:www/rubygem-railties50

.include <bsd.port.mk>
