# New ports collection makefile for:	e_dbus
# Date created:				23 February 2008
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e_dbus
PORTVERSION=	20080223
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	EFL DBUS connectivity library

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_EFL=	ecore
USE_LDCONFIG=	yes

OPTIONS=	EHAL	"Build E HAL module"	on \
		ENM	"Build E NM module"	on \
		ENOT	"Build E notify module" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EHAL)
CONFIGURE_ARGS+=	--enable-ehal
PLIST_SUB+=	EHAL=""
.else
CONFIGURE_ARGS+=	--disable-ehal
PLIST_SUB+=	EHAL="@comment "
.endif

.if !defined(WITHOUT_ENM)
CONFIGURE_ARGS+=	--enable-enm
PLIST_SUB+=	ENM=""
.else
CONFIGURE_ARGS+=	--disable-enm
PLIST_SUB+=	ENM="@comment "
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
