PORTNAME=	actionview
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple, battle-tested conventions and helpers for building web pages
WWW=		https://github.com/rails/rails/tree/main/actionview \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-builder>=3.1<4:devel/rubygem-builder \
		rubygem-cgi>=0:www/rubygem-cgi \
		rubygem-erubi>=1.11<2:www/rubygem-erubi \
		rubygem-rails-dom-testing-rails-gitlab>=2.2<3:textproc/rubygem-rails-dom-testing-rails-gitlab \
		rubygem-rails-html-sanitizer>=1.6<2:textproc/rubygem-rails-html-sanitizer

USES=		cpe gem

CPE_VENDOR=	rubyonrails

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
