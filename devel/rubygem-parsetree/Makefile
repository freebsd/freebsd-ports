# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parsetree
PORTVERSION=	3.0.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	ParseTree-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby parse tree tools

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	Builds with ruby 1.9, but does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
