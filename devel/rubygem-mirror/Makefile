# New ports collection makefile for:	rubygem-mirror
# Date created:		2012-05-10
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mirror
PORTVERSION=	1.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	${GEM_NAME}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A gem to mirror rubygems

RUN_DEPENDS=	rubygem-net-http-persistent>=2.1:${PORTSDIR}/www/rubygem-net-http-persistent

USE_RUBY=		yes
USE_RAKE=		yes
USE_RUBYGEMS=		yes
GEM_NAME=		rubygems-${PORTNAME}-${PORTVERSION}
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
