PORTNAME=	ruby2ruby
PORTVERSION=	2.4.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pure ruby code generator easily from ParseTree's Sexps # '

LICENSE=	MIT

RUN_DEPENDS=	rubygem-ruby_parser>=3.1<4:devel/rubygem-ruby_parser \
		rubygem-sexp_processor>=4.6<5:devel/rubygem-sexp_processor

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/r2r_show

SHEBANG_FILES=	bin/r2r_show

.include <bsd.port.mk>
