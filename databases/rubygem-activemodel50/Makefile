# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	activemodel
PORTVERSION=	5.0.7.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for building modeling frameworks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport50>=${PORTVERSION}:devel/rubygem-activesupport50

PORTSCOUT=	limit:^5\.0\.

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
