# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/gtranslator/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	gtranslator
PORTVERSION=	2.91.6
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for creating GNU gettext translation files

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		itstool:${PORTSDIR}/textproc/itstool \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpeas-1.0.so:${PORTSDIR}/devel/libpeas \
		libgdl-3.so:${PORTSDIR}/x11-toolkits/gdl \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_GNOME=	intlhack gnomeprefix gtk30 libgda5 gtksourceview3 libxml2 \
		introspection:build
USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		python tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-debug \
		--with-gda=5.0 \
		--enable-compile-warnings=no
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gtranslator.gschema.xml \
		org.gnome.gtranslator.plugins.codeview.gschema.xml \
		org.gnome.gtranslator.plugins.open-tran.gschema.xml \
		org.gnome.gtranslator.plugins.translation-memory.gschema.xml

OPTIONS_DEFINE=	DICT
OPTIONS_DEFAULT=DICT
DICT_DESC=	Build dictionary plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDICT}
BUILD_DEPENDS+=	gnome-dictionary>=3.4.0:${PORTSDIR}/deskutils/gnome-dictionary
LIB_DEPENDS+=	libgdict-1.0.so:${PORTSDIR}/deskutils/gnome-dictionary
RUN_DEPENDS+=	gnome-dictionary>=3.4.0:${PORTSDIR}/deskutils/gnome-dictionary
GLIB_SCHEMAS+=	org.gnome.gtranslator.plugins.dictionary.gschema.xml
CONFIGURE_ARGS+=--with-dictionary
PLIST_SUB+=	DICT=""
.else
CONFIGURE_ARGS+=--without-dictionary
PLIST_SUB+=	DICT="@comment "
.endif

.include <bsd.port.mk>
