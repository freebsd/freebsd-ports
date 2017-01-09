# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actionview
PORTVERSION=	5.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rendering framework putting the V in MVC (part of Rails)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport5>=${PORTVERSION}:devel/rubygem-activesupport5 \
		rubygem-builder32>=3.1:devel/rubygem-builder32 \
		rubygem-erubis>=2.7.0:www/rubygem-erubis \
		rubygem-rails-dom-testing>=2.0:textproc/rubygem-rails-dom-testing \
		rubygem-rails-html-sanitizer>=1.0.2:textproc/rubygem-rails-html-sanitizer

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
