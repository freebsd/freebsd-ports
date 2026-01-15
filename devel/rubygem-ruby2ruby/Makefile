PORTNAME=	ruby2ruby
PORTVERSION=	2.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pure ruby code generator easily from ParseTree's Sexps # '
WWW=		https://docs.seattlerb.org/ruby2ruby/ \
		https://github.com/seattlerb/ruby2ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sexp_processor>=4.6<5:devel/rubygem-sexp_processor

USES=		gem shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/r2r_show

SHEBANG_FILES=	bin/r2r_show

.include <bsd.port.mk>
