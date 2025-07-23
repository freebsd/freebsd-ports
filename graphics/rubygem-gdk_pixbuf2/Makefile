PORTNAME=	gdk_pixbuf2
PORTVERSION=	4.3.0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of GdkPixbuf 2.x
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-gio2>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-gio2

USES=		gem gnome
USE_GNOME=	gdkpixbuf

NO_ARCH=	yes

.include <bsd.port.mk>
