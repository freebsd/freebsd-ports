# New ports collection makefile for:	e_dbus
# Date created:				23 February 2008
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e_dbus
DISTVERSION=	1.0.1
PORTEPOCH=	1
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-05-25/base/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EFL DBUS connectivity library

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina ecore libtool_hack librt_hack
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-ebluez  # Linux specific ??

OPTIONS=	EHAL	"Build E HAL module"	 on \
		EUKIT	"Build E upower module"	 on \
		ECONNM	"Build E connman module" on \
		EOFONO	"Build E oFono module"   on \
		ENOT	"Build E notify module"  on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EHAL)
CONFIGURE_ARGS+=	--enable-ehal
PLIST_SUB+=	EHAL=""
.else
CONFIGURE_ARGS+=	--disable-ehal
PLIST_SUB+=	EHAL="@comment "
.endif

.if !defined(WITHOUT_EUKIT)
CONFIGURE_ARGS+=	--enable-eukit
PLIST_SUB+=	EUKIT=""
.else
CONFIGURE_ARGS+=	--disable-eukit
PLIST_SUB+=	EUKIT="@comment "
.endif

.if !defined(WITHOUT_ECONNM)
CONFIGURE_ARGS+=	--enable-econnman
PLIST_SUB+=	ECONNM=""
.else
CONFIGURE_ARGS+=	--disable-econnman
PLIST_SUB+=	ECONNM="@comment "
.endif

.if !defined(WITHOUT_EOFONO)
CONFIGURE_ARGS+=	--enable-eofono
PLIST_SUB+=	EOFONO=""
.else
CONFIGURE_ARGS+=	--disable-eofono
PLIST_SUB+=	EOFONO="@comment "
.endif

.if !defined(WITHOUT_ENOT)
CONFIGURE_ARGS+=	--enable-enotify
PLIST_SUB+=	ENOT=""
USE_EFL+=	evas
.else
CONFIGURE_ARGS+=	--disable-enotify
PLIST_SUB+=	ENOT="@comment "
.endif

.include <bsd.port.post.mk>
