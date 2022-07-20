PORTNAME=	actionview
PORTVERSION=	5.0.7.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rendering framework putting the V in MVC (part of Rails)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport50>=${PORTVERSION}:devel/rubygem-activesupport50 \
		rubygem-builder>=3.1<4:devel/rubygem-builder \
		rubygem-erubis>=2.7.0<2.8:www/rubygem-erubis \
		rubygem-rails-dom-testing-rails50>=2.0<3:textproc/rubygem-rails-dom-testing-rails50 \
		rubygem-rails-html-sanitizer>=1.0.3<2:textproc/rubygem-rails-html-sanitizer

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails

PORTSCOUT=	limit:^5\.0\.

.include <bsd.port.mk>
