PORTNAME=	ruby-lsp
PORTVERSION=	0.26.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Opinionated language server for Ruby
WWW=		https://shopify.github.io/ruby-lsp/ \
		https://github.com/Shopify/ruby-lsp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-language_server-protocol>=3.17.0<3.18:devel/rubygem-language_server-protocol \
		rubygem-prism>=1.2<2.0:textproc/rubygem-prism \
		rubygem-rbs>=3<5:devel/rubygem-rbs

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/ruby-lsp \
		bin/ruby-lsp-check \
		bin/ruby-lsp-launcher \
		bin/ruby-lsp-test-exec

.include <bsd.port.mk>
