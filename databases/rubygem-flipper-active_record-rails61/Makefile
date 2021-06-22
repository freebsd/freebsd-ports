# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	flipper-active_record
PORTVERSION=	0.21.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ActiveRecord adapter for Flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord61>=5.0<7:databases/rubygem-activerecord61 \
		rubygem-flipper>=${PORTVERSION}<0.22:devel/rubygem-flipper

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
