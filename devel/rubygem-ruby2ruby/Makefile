# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	ruby2ruby
PORTVERSION=	2.0.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A pure ruby code generator easily from ParseTree's Sexps # '

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sexp_processor>=4.0:${PORTSDIR}/devel/rubygem-sexp_processor \
		rubygem-ruby_parser>=3.1:${PORTSDIR}/devel/rubygem-ruby_parser

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/r2r_show

.include <bsd.port.mk>
