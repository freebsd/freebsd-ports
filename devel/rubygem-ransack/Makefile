# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ransack
PORTVERSION=	2.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Successor to the MetaSearch gem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack5>=5.0:www/rubygem-actionpack5 \
		rubygem-activerecord5>=5.0:databases/rubygem-activerecord5 \
		rubygem-activesupport5>=5.0:devel/rubygem-activesupport5 \
		rubygem-i18n>=0:devel/rubygem-i18n \
		rubygem-polyamorous>=${PORTVERSION}:devel/rubygem-polyamorous

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	skipv:2.3.1,2.3.2

.include <bsd.port.mk>
