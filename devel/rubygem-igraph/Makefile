# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	igraph
PORTVERSION=	0.9.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby extension for using the igraph library

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/igraph/igraph.h:${PORTSDIR}/math/igraph

BROKEN=		does not build with igraph-0.7.1

CONFIGURE_ARGS=	--with-igraph-include=${LOCALBASE}/include/igraph \
		--without-igraph-lib=${LOCALBASE}/lib
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
