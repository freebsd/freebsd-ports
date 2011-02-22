# Ports collection makefile for:	rubygem-parsetree
# Date created:				13 April 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	parsetree
PORTVERSION=	3.0.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	ParseTree-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby parse tree tools

RUN_DEPENDS=	rubygem-inline>=3.7.0:${PORTSDIR}/devel/rubygem-inline \
		rubygem-sexp_processor>=3.0.1:${PORTSDIR}/devel/rubygem-sexp_processor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/parse_tree_abc	\
		bin/parse_tree_audit	\
		bin/parse_tree_deps	\
		bin/parse_tree_show

GEM_NAME=	${DISTNAME}

.include <bsd.port.mk>
