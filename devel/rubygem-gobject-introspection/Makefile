# $FreeBSD$

PORTNAME=	gobject-introspection
PORTVERSION=	3.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GObjectIntrospection

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-glib2>=${PORTVERSION}:devel/rubygem-glib2

BROKEN_sparc64=	Does not build: fails to compile rb-gi-function-info.c

USE_GNOME=	introspection
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
