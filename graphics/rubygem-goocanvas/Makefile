# $FreeBSD$

PORTNAME=	goocanvas
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GooCanvas is a Ruby binding of GooCanvas

LICENSE=	LGPL21+

LIB_DEPENDS=	libgoocanvas-2.0.so:graphics/goocanvas2
RUN_DEPENDS=	rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection \
		rubygem-gtk3>=${PORTVERSION}:x11-toolkits/rubygem-gtk3

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
