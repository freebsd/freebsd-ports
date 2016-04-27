# $FreeBSD$

PORTNAME=	rsvg2
PORTVERSION=	3.0.8
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for librsvg2

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-cairo>=1.12.8:graphics/rubygem-cairo \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2

USE_GNOME=	librsvg2
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
