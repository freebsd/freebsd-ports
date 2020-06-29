# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flipper-ui
PORTVERSION=	0.17.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	017

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rack middleware that provides a fully featured web interface

LICENSE=	MIT

RUN_DEPENDS=	rubygem-erubi>=1.0.0<2.0.0:www/rubygem-erubi \
		rubygem-flipper017>=${PORTVERSION}<0.18:devel/rubygem-flipper017 \
		rubygem-rack>=1.4,3<3,3:www/rubygem-rack \
		rubygem-rack-protection>=1.5.3<2.1.0:www/rubygem-rack-protection

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.17\.

.include <bsd.port.mk>
