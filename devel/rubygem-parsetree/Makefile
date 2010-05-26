# Ports collection makefile for:	rubygem-parsetree
# Date created:				13 April 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	parsetree
PORTVERSION=	3.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	ParseTree-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby parse tree tools

BUILD_DEPENDS=	rubygem-inline>=3.7.0:${PORTSDIR}/devel/rubygem-inline \
		rubygem-sexp_processor>=3.0.1:${PORTSDIR}/devel/rubygem-sexp_processor \
		rubygem-hoe>=1.8.2:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/parse_tree_abc	\
		bin/parse_tree_audit	\
		bin/parse_tree_deps	\
		bin/parse_tree_show

GEM_NAME=	${DISTNAME}

.include <bsd.port.mk>
