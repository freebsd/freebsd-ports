# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gedit-plugins
PORTVERSION=	3.28.1
PORTREVISION=	3
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gedit>=0:editors/gedit \
		valac:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libgit2-glib-1.0.so:devel/libgit2-glib
RUN_DEPENDS=	gedit>=0:editors/gedit

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake gnome libtool localbase pathfix pkgconfig \
		python:3.4+ tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 gtksourceview3 intlhack introspection
USE_CSTD=	c11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml \
		org.gnome.gedit.plugins.wordcompletion.gschema.xml

USES+=		python
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS+=	libgucharmap_2_90.so:deskutils/gucharmap
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}
USE_GNOME+=	vte3
CONFIGURE_ARGS+=--enable-python
GLIB_SCHEMAS+=	org.gnome.gedit.plugins.terminal.gschema.xml \
		org.gnome.gedit.plugins.translate.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's| \\t\\r\\n\\f|[:space:]|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
