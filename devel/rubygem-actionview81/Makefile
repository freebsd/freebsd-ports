PORTNAME=	actionview
PORTVERSION=	8.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, battle-tested conventions and helpers for building web pages
WWW=		https://github.com/rails/rails/tree/main/actionview \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport81 \
		rubygem-builder>=3.1<4:devel/rubygem-builder \
		rubygem-erubi>=1.11<2:www/rubygem-erubi \
		rubygem-rails-dom-testing-rails81>=2.2<3:textproc/rubygem-rails-dom-testing-rails81 \
		rubygem-rails-html-sanitizer>=1.6<2:textproc/rubygem-rails-html-sanitizer

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails

PORTSCOUT=	limit:^8\.1\.

.include <bsd.port.mk>
