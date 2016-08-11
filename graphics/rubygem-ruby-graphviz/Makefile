# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	ruby-graphviz
PORTVERSION=	1.2.2
CATEGORIES=	graphics ruby rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Interface to the GraphViz Graphing Tool

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/gxl2dot:graphics/graphviz

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/dot2ruby bin/gem2gv bin/git2gv bin/ruby2gv bin/xml2gv

.include <bsd.port.mk>
