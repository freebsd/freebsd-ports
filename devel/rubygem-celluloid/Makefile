# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	celluloid
PORTVERSION=	0.15.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Build concurrent programs out of concurrent objects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-timers>=1.1.0:${PORTSDIR}/devel/rubygem-timers

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.8
BROKEN=		does not build with ruby ${RUBY_VER}
.endif

.include <bsd.port.post.mk>
