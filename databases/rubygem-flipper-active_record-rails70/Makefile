PORTNAME=	flipper-active_record
PORTVERSION=	0.28.3
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ActiveRecord adapter for Flipper
WWW=		https://github.com/jnunemaker/flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord70>=4.2<8:databases/rubygem-activerecord70 \
		rubygem-flipper-gitlab>=${PORTVERSION}<0.29:devel/rubygem-flipper-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
