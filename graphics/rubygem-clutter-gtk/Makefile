PORTNAME=	clutter-gtk
PORTVERSION=	3.4.4
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of Clutter-GTK

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
LIB_DEPENDS=	libclutter-gtk-1.0.so:graphics/clutter-gtk3
RUN_DEPENDS=	rubygem-clutter>=${PORTVERSION}:graphics/rubygem-clutter \
		rubygem-clutter-gdk>=${PORTVERSION}:graphics/rubygem-clutter-gdk \
		rubygem-gtk3>=${PORTVERSION}:x11-toolkits/rubygem-gtk3

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
