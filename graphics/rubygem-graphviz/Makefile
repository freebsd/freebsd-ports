# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	1.0.9
CATEGORIES=	graphics ruby rubygems
MASTER_SITES=	RG
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Interface to the GraphViz Graphing Tool

RUN_DEPENDS=	${LOCALBASE}/bin/gxl2dot:${PORTSDIR}/graphics/graphviz \
		rubygem-treetop>=1.4.2:${PORTSDIR}/devel/rubygem-treetop

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ruby2gv bin/gem2gv bin/dot2ruby bin/git2gv bin/xml2gv

.include <bsd.port.mk>
