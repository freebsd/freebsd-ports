# Ports collection makefile for:	dep_selector
# Date created:				13 Dec 2011
# Whom:					Scott Sanders <scott@jssjr.com>
#
# $FreeBSD$

PORTNAME=	dep_selector
PORTVERSION=	0.0.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Find a valid assignment of package versions

RUN_DEPENDS=	gecode>=3.5.0:${PORTSDIR}/devel/gecode

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

CONFIGURE_ARGS+=	--with-opt-dir=${LOCALBASE}

.include <bsd.port.mk>
