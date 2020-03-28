# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actionview
PORTVERSION=	5.2.4.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rendering framework putting the V in MVC (part of Rails)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport52>=${PORTVERSION}:devel/rubygem-activesupport52 \
		rubygem-builder>=3.1<4:devel/rubygem-builder \
		rubygem-erubi>=1.4<2:www/rubygem-erubi \
		rubygem-rails-dom-testing-rails52>=2.0<3:textproc/rubygem-rails-dom-testing-rails52 \
		rubygem-rails-html-sanitizer>=1.0.3<2:textproc/rubygem-rails-html-sanitizer

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.2\.

.include <bsd.port.mk>
