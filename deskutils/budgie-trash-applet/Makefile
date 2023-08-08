PORTNAME=	budgie-trash-applet
DISTVERSION=	2.1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	deskutils budgie

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Trash applet for the Budgie desktop
WWW=		https://github.com/EbonJaeger/budgie-trash-applet

LICENSE=	APACHE20

BUILD_DEPENDS=	sassc:textproc/sassc
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libpeas-1.0.so:devel/libpeas

USES=		budgie gettext gnome meson pkgconfig
USE_BUDGIE=	libbudgie
USE_GNOME=	glib20 gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	EbonJaeger

GLIB_SCHEMAS=	com.github.ebonjaeger.budgie-trash-applet.gschema.xml

.include <bsd.port.mk>
