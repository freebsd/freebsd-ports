# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ransack
PORTVERSION=	2.3.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Successor to the MetaSearch gem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activerecord52>=5.2.1:databases/rubygem-activerecord52 \
		rubygem-activesupport52>=5.2.1:devel/rubygem-activesupport52 \
		rubygem-i18n>=0:devel/rubygem-i18n \
		rubygem-polyamorous>=${PORTVERSION}:devel/rubygem-polyamorous

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
