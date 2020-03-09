# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	warden
PORTVERSION=	1.2.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	127

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Rack middleware that provides authentication for rack applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rack16>=1.6<2:www/rubygem-rack16

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
