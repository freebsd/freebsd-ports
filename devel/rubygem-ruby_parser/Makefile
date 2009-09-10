# New ports collection makefile for: rubygem-ruby_parser
# Date created:		18 June 2009
# Whom:		Espen Volden aka voldern <voldern@hoeggen.net>
#
# $FreeBSD$
#

PORTNAME=	ruby_parser
PORTVERSION=	2.0.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RUBYFORGE/parsetree

MAINTAINER=	voldern@hoeggen.net
COMMENT=	A ruby parser written in pure ruby

BUILD_DEPENDS=	rubygem-sexp_processor>=3.0.1:${PORTSDIR}/devel/rubygem-sexp_processor \
		rubygem-parsetree>=0:${PORTSDIR}/devel/rubygem-parsetree \
		rubygem-hoe>=1.8.2:${PORTSDIR}/devel/rubygem-hoe

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ruby_parse

.include <bsd.port.mk>
