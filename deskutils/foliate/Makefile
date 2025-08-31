PORTNAME=	foliate
PORTVERSION=	3.3.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Simple and modern GTK eBook viewer
WWW=		https://johnfactotum.github.io/foliate/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		gjs-console:lang/gjs
LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60
RUN_DEPENDS=	gjs-console:lang/gjs

USES=		desktop-file-utils gnome localbase meson pkgconfig python shebangfix
USE_GNOME=	cairo gtk40 introspection
GLIB_SCHEMAS=	com.github.johnfactotum.Foliate.gschema.xml

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

USE_GITHUB=	yes
GH_ACCOUNT=	johnfactotum
GH_PROJECT=	foliate-js:js
GH_TAGNAME=	052123b:js
GH_SUBDIR=	src/foliate-js:js

.include <bsd.port.mk>
