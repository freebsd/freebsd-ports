# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	ruby2ruby
PORTVERSION=	2.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pure ruby code generator easily from ParseTree's Sexps # '

LICENSE=	MIT

RUN_DEPENDS=	rubygem-ruby_parser>=3.1:devel/rubygem-ruby_parser \
		rubygem-sexp_processor>=4.6:devel/rubygem-sexp_processor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

PLIST_FILES=	bin/r2r_show

SHEBANG_FILES=	bin/r2r_show

.include <bsd.port.mk>
