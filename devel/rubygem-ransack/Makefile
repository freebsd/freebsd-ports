# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ransack
PORTVERSION=	2.4.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Successor to the MetaSearch gem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_RUBY25=	yes

RUN_DEPENDS=	rubygem-activerecord52>=5.2.4:databases/rubygem-activerecord52 \
		rubygem-activesupport52>=5.2.4:devel/rubygem-activesupport52 \
		rubygem-i18n>=0:devel/rubygem-i18n

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
