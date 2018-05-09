# $FreeBSD$

PORTNAME=	flipper-active_record
PORTVERSION=	0.11.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	011

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActiveRecord adapter for Flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord4>=3.2:databases/rubygem-activerecord4 \
		rubygem-flipper011>=${PORTVERSION}:devel/rubygem-flipper011

PORTSCOUT=	limit:^0\.11\.

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
