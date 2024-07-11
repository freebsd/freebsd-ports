PORTNAME=	neovim
PORTVERSION=	0.10.0
CATEGORIES=	editors rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for neovim
WWW=		https://github.com/neovim/neovim-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	nvim:editors/neovim \
		rubygem-msgpack>=1.1<2:devel/rubygem-msgpack \
		rubygem-multi_json>=1.0<2:devel/rubygem-multi_json
TEST_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-rake>=0:devel/rubygem-rake \
		rubygem-rspec>=0:devel/rubygem-rspec

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/neovim-ruby-host

.include <bsd.port.mk>
