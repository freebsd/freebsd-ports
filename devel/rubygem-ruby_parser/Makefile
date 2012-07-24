# New ports collection makefile for: rubygem-ruby_parser
# Date created:		18 June 2009
# Whom:		Espen Volden aka voldern <voldern@hoeggen.net>
#
# $FreeBSD$
#

PORTNAME=	ruby_parser
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	voldern@hoeggen.net
COMMENT=	A ruby parser written in pure ruby

RUN_DEPENDS=	rubygem-sexp_processor>=3.0:${PORTSDIR}/devel/rubygem-sexp_processor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ruby_parse

.include <bsd.port.mk>
