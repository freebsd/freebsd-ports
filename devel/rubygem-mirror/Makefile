# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mirror
PORTVERSION=	1.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	${GEM_NAME}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Mirror rubygems

RUN_DEPENDS=	rubygem-net-http-persistent>=2.1:${PORTSDIR}/www/rubygem-net-http-persistent

USE_RUBY=		yes
USE_RAKE=		yes
USE_RUBYGEMS=		yes
GEM_NAME=		rubygems-${PORTNAME}-${PORTVERSION}
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
