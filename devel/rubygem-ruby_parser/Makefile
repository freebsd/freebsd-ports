# Created by: Espen Volden aka voldern <voldern@hoeggen.net>
# $FreeBSD$

PORTNAME=	ruby_parser
PORTVERSION=	3.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	voldern@hoeggen.net
COMMENT=	A ruby parser written in pure ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sexp_processor>=4.1:${PORTSDIR}/devel/rubygem-sexp_processor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ruby_parse \
		bin/ruby_parse_extract_error

.include <bsd.port.mk>
