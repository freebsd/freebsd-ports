# $FreeBSD$

PORTNAME=	rsvg2
PORTVERSION=	3.2.1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for librsvg2

LICENSE=	LGPL21+

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-cairo>=1.12.8:graphics/rubygem-cairo \
		rubygem-cairo-gobject>=${PORTVERSION}:devel/rubygem-cairo-gobject \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2

NO_ARCH=	yes
USE_GNOME=	librsvg2
USE_RUBY=	yes
USES=		gem gnome

.include <bsd.port.mk>
