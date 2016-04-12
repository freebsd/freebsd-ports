# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gedit-plugins
PORTVERSION=	3.18.0
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 3

BUILD_DEPENDS=	gedit>=0:editors/gedit \
		valac:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libgit2-glib-1.0.so:devel/libgit2-glib
RUN_DEPENDS=	gedit>=0:editors/gedit

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool pathfix pkgconfig \
		python:3 tar:xz
USE_GNOME=	gtk30 gtksourceview3 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml \
		org.gnome.gedit.plugins.wordcompletion.gschema.xml

USES+=		python
BUILD_DEPENDS+=	py3?-dbus>=0:devel/py3-dbus
LIB_DEPENDS+=	libgucharmap_2_90.so:deskutils/gucharmap
RUN_DEPENDS+=	py3?-dbus>=0:devel/py3-dbus \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py3-libpeas
USE_GNOME+=	vte3
CONFIGURE_ARGS+=--enable-python
GLIB_SCHEMAS+=	org.gnome.gedit.plugins.terminal.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's| \\t\\r\\n\\f|[:space:]|g' \
		${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif

PLIST_SUB+=	PYOEXTENSION=${PYOEXTENSION} \
		PYVER=${PYTHON_VER:S/.//}

.include <bsd.port.post.mk>
