PORTNAME=	flipper-active_record
PORTVERSION=	0.25.4
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ActiveRecord adapter for Flipper
WWW=		https://github.com/jnunemaker/flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord61>=5.0<7:databases/rubygem-activerecord61 \
		rubygem-flipper025>=${PORTVERSION}<0.26:devel/rubygem-flipper025

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
