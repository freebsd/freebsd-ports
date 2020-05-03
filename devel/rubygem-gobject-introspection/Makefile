# $FreeBSD$

PORTNAME=	gobject-introspection
PORTVERSION=	3.4.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for GObjectIntrospection

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BROKEN_sparc64=	does not build: fails to compile rb-gi-function-info.c

RUN_DEPENDS=	rubygem-glib2>=${PORTVERSION}:devel/rubygem-glib2

USES=		gem gnome
USE_GNOME=	introspection
USE_RUBY=	yes

.include <bsd.port.mk>
