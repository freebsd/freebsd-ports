# $FreeBSD$

PORTNAME=	rsvg2
PORTVERSION=	3.4.2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for librsvg2

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}:devel/rubygem-cairo-gobject \
		rubygem-gdk_pixbuf2>=${PORTVERSION}:graphics/rubygem-gdk_pixbuf2

USES=		gem gnome
USE_GNOME=	librsvg2
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
