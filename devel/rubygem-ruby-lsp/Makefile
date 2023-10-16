PORTNAME=	ruby-lsp
PORTVERSION=	0.11.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Opinionated language server for Ruby
WWW=		https://shopify.github.io/ruby-lsp/ \
		https://github.com/Shopify/ruby-lsp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-language_server-protocol>=3.17.0<3.18:devel/rubygem-language_server-protocol \
		rubygem-sorbet-runtime>=0.5.5685:devel/rubygem-sorbet-runtime \
		rubygem-yarp>=0.12<0.13:textproc/rubygem-yarp

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/ruby-lsp \
		bin/ruby-lsp-check

.include <bsd.port.mk>
