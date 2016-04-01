# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gedit
PORTVERSION=	3.18.3
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GNOME 3 Desktop Environment

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		vala:lang/vala \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libpeas-gtk-1.0.so:devel/libpeas \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py3-libpeas

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool \
		pathfix pkgconfig python:3 tar:xz
USE_GNOME=	gtksourceview3 intlhack introspection:build \
		libxml2 py3gobject3
USE_XORG=	sm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-updater \
		--enable-python
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION="3.14"
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.plugins.externaltools.gschema.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.pythonconsole.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif

PLIST_SUB+=	PYOEXTENSION=${PYOEXTENSION} \
		PYVER=${PYTHON_VER:S/.//}

post-patch:
	@${REINPLACE_CMD} -e 's|=python|=${PYTHON_CMD}|g' \
		${WRKSRC}/py-compile

.include <bsd.port.post.mk>
