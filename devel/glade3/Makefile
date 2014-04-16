# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/glade3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	glade3
PORTVERSION=	3.8.3
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for GTK+/GNOME

CONFLICTS=	glade-3.*
PORTSCOUT=	ignore

INSTALLS_ICONS=	yes
USE_GNOME=	gtk20 libxml2 gnomeprefix gnomedocutils
USES=		gmake gettext libtool pathfix desktop-file-utils pkgconfig tar:xz
INSTALLS_OMF=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/gladeui

OPTIONS_DEFINE=	GNOME PYTHON
OPTIONS_DEFAULT=PYTHON
GNOME_DESC=	GNOME UI widget support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	libgnomeui
CONFIGURE_ARGS+=--enable-gnome
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gnome
PLIST_SUB+=	GNOME:=""
.else
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB+=	GNOME:="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
USE_GNOME+=	pygtk2
PLIST_SUB+=	PYTHON:=""
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON:="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/glade3/bindings

.include <bsd.port.mk>
