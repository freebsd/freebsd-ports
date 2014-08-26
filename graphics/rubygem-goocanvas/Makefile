# $FreeBSD$

PORTNAME=	goocanvas
PORTVERSION=	2.2.0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GooCanvas is a Ruby binding of GooCanvas

RUN_DEPENDS=	rubygem-gobject-introspection>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gobject-introspection \
		rubygem-gtk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk3
LIB_DEPENDS=	libgoocanvas-2.0.so:${PORTSDIR}/graphics/goocanvas2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
