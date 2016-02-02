# $FreeBSD$

PORTNAME=	clutter
PORTVERSION=	3.0.7
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for Clutter

LICENSE=	LGPL21+

LIB_DEPENDS=	libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter
RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-cairo-gobject \
		rubygem-gobject-introspection>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gobject-introspection \
		rubygem-pango>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-pango

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
