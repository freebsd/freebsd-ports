PORTNAME=	ruby_parser
PORTVERSION=	3.15.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	voldern@hoeggen.net
COMMENT=	Ruby parser written in pure ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sexp_processor>=4.9<5:devel/rubygem-sexp_processor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		cpe gem shebangfix
CPE_VENDOR=	ryan_davis

PLIST_FILES=	bin/ruby_parse \
		bin/ruby_parse_extract_error

SHEBANG_FILES=	bin/* \
		compare/normalize.rb

.include <bsd.port.mk>
