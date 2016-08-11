# Created by: Espen Volden aka voldern <voldern@hoeggen.net>
# $FreeBSD$

PORTNAME=	ruby_parser
PORTVERSION=	3.6.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	voldern@hoeggen.net
COMMENT=	Ruby parser written in pure ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sexp_processor>=4.1:devel/rubygem-sexp_processor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	bin/ruby_parse*

PLIST_FILES=	bin/ruby_parse \
		bin/ruby_parse_extract_error

.include <bsd.port.mk>
