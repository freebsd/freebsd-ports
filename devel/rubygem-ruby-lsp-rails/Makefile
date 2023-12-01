PORTNAME=	ruby-lsp-rails
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby LSP addon that adds extra editor functionality for Rails applications
WWW=		https://shopify.github.io/ruby-lsp-rails/ \
		https://github.com/Shopify/ruby-lsp-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rails71>=6.0:www/rubygem-rails71 \
		rubygem-ruby-lsp>=0.12.0<0.14.0:devel/rubygem-ruby-lsp \
		rubygem-sorbet-runtime>=0.5.9897:devel/rubygem-sorbet-runtime

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
