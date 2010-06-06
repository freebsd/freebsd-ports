# New ports collection makefile for:	graphviz
# Date created:		21 march, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	graphviz
PORTVERSION=	0.9.8
PORTREVISION=	3
CATEGORIES=	graphics ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-asp
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Ruby Interface to the GraphViz Graphing Tool

RUN_DEPENDS=	${LOCALBASE}/bin/gxl2dot:${PORTSDIR}/graphics/graphviz \
	rubygem-treetop>=1.4.2:${PORTSDIR}/devel/rubygem-treetop

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ruby2gv bin/gem2gv

.include <bsd.port.mk>
