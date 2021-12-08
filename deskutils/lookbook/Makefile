PORTNAME=	lookbook
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Browse and find system icons

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy

USES=		gettext-tools gnome meson pkgconfig python:3.6+,build
USE_GITHUB=	yes
GH_ACCOUNT=	danrabbit
USE_GNOME=	glib20 gtk30 gtksourceview4
GLIB_SCHEMAS=	com.github.danrabbit.lookbook.gschema.xml

.include <bsd.port.mk>
