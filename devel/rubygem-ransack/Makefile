# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ransack
PORTVERSION=	1.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Successor to the MetaSearch gem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=3.0:www/rubygem-actionpack4 \
		rubygem-activerecord4>=3.0:databases/rubygem-activerecord4 \
		rubygem-activesupport4>=3.0:devel/rubygem-activesupport4 \
		rubygem-i18n>=0:devel/rubygem-i18n \
		rubygem-polyamorous>=1.2:devel/rubygem-polyamorous

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
