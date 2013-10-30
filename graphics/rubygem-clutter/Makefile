# $FreeBSD$

PORTNAME=	clutter
PORTVERSION=	2.0.2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Clutter

RUN_DEPENDS=	rubygem-gobject-introspection>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gobject-introspection \
		rubygem-cairo-gobject>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-cairo-gobject
LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
