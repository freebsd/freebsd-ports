# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	nemiver
PORTVERSION=	0.8.2
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	romain@FreeBSD.org
COMMENT=	A C/C++ Debugger for GNOME

LIB_DEPENDS=	libboost_unit_test_framework.so:${PORTSDIR}/devel/boost-libs \
		libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libgtksourceviewmm-2.so:${PORTSDIR}/x11-toolkits/libgtksourceviewmm
BUILD_DEPENDS=	${LOCALBASE}/bin/gdb:${PORTSDIR}/devel/gdb
RUN_DEPENDS=	${LOCALBASE}/bin/gdb:${PORTSDIR}/devel/gdb

OPTIONS_DEFINE=	GHEX
GHEX_DESC=	Enable memory view

BROKEN=		Does not build with current environment, and some GTK3 bits are missing for an update

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	ac_cv_path_GDB_PROG=${LOCALBASE}/bin/gdb
USE_GNOME=	gnomeprefix gnomehack intltool gnomedocutils gconf2 vte
USE_GCC=	yes
USE_LDCONFIG=	yes
USES=		gettext gmake pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
MAN1=		nemiver.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if !exists(${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc)
CONFIGURE_ARGS+=--enable-gsettings=no
PLIST_SUB+=	GSETTINGS="@comment " GCONF=""
GCONF_SCHEMAS=	nemiver-workbench.schemas nemiver-dbgperspective.schemas
.else
# Technically, the port is already installed in this case so fill-in
# BUILD_DEPENDS for the sake of consistency only.
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
CONFIGURE_ARGS+=--enable-gsettings=yes
PLIST_SUB+=	GSETTINGS="" GCONF="@comment "
GLIB_SCHEMAS=	org.nemiver.gschema.xml
.endif

.if ${PORT_OPTIONS:MGHEX}
CONFIGURE_ARGS+=--enable-memoryview
PLIST_SUB+=	GHEX=""
LIB_DEPENDS+=	gtkhex.0:${PORTSDIR}/editors/ghex
.else
CONFIGURE_ARGS+=--disable-memoryview
PLIST_SUB+=	GHEX="@comment "
.endif

.include <bsd.port.mk>
