# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flipper-active_record
PORTVERSION=	0.17.2
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	017

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ActiveRecord adapter for Flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord60>=4.2<7:databases/rubygem-activerecord60 \
		rubygem-flipper017>=${PORTVERSION}<0.18:devel/rubygem-flipper017

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.17\.

.include <bsd.port.mk>
