PORTNAME=	clutter-gtk
PORTVERSION=	4.3.0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of Clutter-GTK
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
LIB_DEPENDS=	libclutter-gtk-1.0.so:graphics/clutter-gtk3
RUN_DEPENDS=	rubygem-clutter>=${PORTVERSION}<${PORTVERSION}_99:graphics/rubygem-clutter \
		rubygem-clutter-gdk>=${PORTVERSION}<${PORTVERSION}_99:graphics/rubygem-clutter-gdk \
		rubygem-gtk3>=${PORTVERSION}<${PORTVERSION}_99:x11-toolkits/rubygem-gtk3

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
