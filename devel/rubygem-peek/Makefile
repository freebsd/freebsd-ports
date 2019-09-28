# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	peek
PORTVERSION=	1.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Take a peek into your Rails application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

OPTIONS_RADIO=	RAILS
OPTIONS_RADIO_RAILS=	RAILS4 RAILS5
OPTIONS_DEFAULT=RAILS5
RAILS4_DESC=	Use Rails 4
RAILS5_DESC=	Use Rails 5

RAILS4_RUN_DEPENDS=	rubygem-railties4>=4.0.0:www/rubygem-railties4
RAILS5_RUN_DEPENDS=	rubygem-railties5>=4.0.0:www/rubygem-railties5

.include <bsd.port.mk>
