PORTNAME=	rsvg2
PORTVERSION=	4.3.0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of librsvg 2.x
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-cairo-gobject>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-cairo-gobject \
		rubygem-gdk_pixbuf2>=${PORTVERSION}<${PORTVERSION}_99:graphics/rubygem-gdk_pixbuf2

USES=		gem gnome
USE_GNOME=	librsvg2

NO_ARCH=	yes

.include <bsd.port.mk>
