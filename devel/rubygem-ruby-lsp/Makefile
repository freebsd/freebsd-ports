PORTNAME=	ruby-lsp
PORTVERSION=	0.14.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Opinionated language server for Ruby
WWW=		https://shopify.github.io/ruby-lsp/ \
		https://github.com/Shopify/ruby-lsp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-language_server-protocol>=3.17.0<3.18:devel/rubygem-language_server-protocol \
		rubygem-prism>=0.22.0<0.25:textproc/rubygem-prism \
		rubygem-sorbet-runtime>=0.5.10782:devel/rubygem-sorbet-runtime

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/ruby-lsp \
		bin/ruby-lsp-check \
		bin/ruby-lsp-doctor

.include <bsd.port.mk>
