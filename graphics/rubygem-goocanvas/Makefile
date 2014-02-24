# $FreeBSD$

PORTNAME=	goocanvas
PORTVERSION=	2.1.0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GooCanvas is a Ruby binding of GooCanvas

RUN_DEPENDS=	rubygem-gtk2>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk2
LIB_DEPENDS=	libgoocanvas-2.0.so:${PORTSDIR}/graphics/goocanvas2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
