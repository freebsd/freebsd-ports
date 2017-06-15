# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ruby-shout
PORTVERSION=	2.2.2
CATEGORIES=	audio rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding to the libshout library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libshout.so:audio/libshout

CONFIGURE_ARGS=	--with-opt-include="${LOCALBASE}/include"
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
