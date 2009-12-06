# New ports collection makefile for:	graphviz
# Date created:		21 march, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	graphviz
PORTVERSION=	0.9.6
CATEGORIES=	graphics ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-asp
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Ruby Interface to the GraphViz Graphing Tool

BUILD_DEPENDS=	rubygem-treetop>=1.4.2:${PORTSDIR}/devel/rubygem-treetop
RUN_DEPENDS=	${LOCALBASE}/bin/gxl2dot:${PORTSDIR}/graphics/graphviz

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ruby2gv

.include <bsd.port.mk>
