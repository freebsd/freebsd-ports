# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shout
PORTVERSION=	2.2.1
CATEGORIES=	audio rubygems
MASTER_SITES=	RG
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby binding to the libshout library

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
CONFIGURE_ARGS=		--with-opt-include="${LOCALBASE}/include"

.include <bsd.port.mk>
