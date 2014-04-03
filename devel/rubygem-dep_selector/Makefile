# Created by: Scott Sanders <scott@jssjr.com>
# $FreeBSD$

PORTNAME=	dep_selector
PORTVERSION=	0.0.8
PORTREVISION=	1
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
