# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actionview
PORTVERSION=	5.0.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rendering framework putting the V in MVC (part of Rails)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport50>=${PORTVERSION}:devel/rubygem-activesupport50 \
		rubygem-builder>=3.1:devel/rubygem-builder \
		rubygem-erubis>=2.7.0:www/rubygem-erubis \
		rubygem-rails-dom-testing>=2.0:textproc/rubygem-rails-dom-testing \
		rubygem-rails-html-sanitizer>=1.0.3:textproc/rubygem-rails-html-sanitizer

PORTSCOUT=	limit:^5\.0\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
