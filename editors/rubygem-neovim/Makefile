# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	neovim
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	editors rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for neovim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	nvim:editors/neovim \
		rubygem-msgpack>=1.1<2:devel/rubygem-msgpack \
		rubygem-multi_json>=1.0<2:devel/rubygem-multi_json
TEST_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-rake>=0:devel/rubygem-rake \
		rubygem-rspec>=0:devel/rubygem-rspec

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/neovim-ruby-host

.include <bsd.port.mk>
