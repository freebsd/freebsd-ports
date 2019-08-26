# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	default_value_for
PORTVERSION=	3.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	32

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Define default values for ActiveRecord models in a declarative manner

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	rubygem-activerecord52>=3.2.0<6.0:databases/rubygem-activerecord52

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.2\.

.include <bsd.port.mk>
