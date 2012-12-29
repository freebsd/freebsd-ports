# New ports collection makefile for:	gvfs
# Date created:		2007-11-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gvfs/Makefile,v 1.70 2011/01/31 19:06:42 kwm Exp $
#

PORTNAME=	gvfs
PORTVERSION=	1.6.6
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
		soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring

USE_BZIP2=	yes
USE_GNOME=	glib20 gnomehack gnomeprefix intlhack gconf2
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-obexftp \
		--disable-afc
OPTIONS=	FUSE "Enable fuse" off \
		AVAHI "Enable AVAHI" on \
		SAMBA "Enable Samba" on \
		GPHOTO2 "Enable Gphoto 2 camera support (required HAL)" on \
		CDDA "Enable CDDA (required HAL)" on \
		HAL "Enable HAL" on

.include <bsd.port.pre.mk>

.if defined(WITH_FUSE)
USE_FUSE=	yes
PLIST_SUB+=	FUSE=""
.else
CONFIGURE_ARGS+=	--disable-fuse
PLIST_SUB+=	FUSE="@comment "
.endif

.if defined(WITH_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SMB=""
.else
CONFIGURE_ARGS+=	--disable-samba
PLIST_SUB+=	SMB="@comment "
.endif

.if defined(WITH_CDDA) && !defined(WITHOUT_HAL)
LIB_DEPENDS+=	cdio_paranoia.1:${PORTSDIR}/sysutils/libcdio
PLIST_SUB+=	CDDA=""
.else
CONFIGURE_ARGS+=	--disable-cdda
PLIST_SUB+=	CDDA="@comment "
.endif

.if defined(WITH_GPHOTO2) && !defined(WITHOUT_HAL)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
PLIST_SUB+=	GPHOTO2=""
.else
CONFIGURE_ARGS+=	--disable-gphoto2
PLIST_SUB+=	GPHOTO2="@comment "
.endif

.if defined(WITH_AVAHI)
LIB_DEPENDS+=	avahi-client.3:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	AVAHI=""
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	AVAHI="@comment "
.endif

.if defined(WITH_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
RUN_DEPENDS+=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount
PLIST_SUB+=	HAL=""
.else
CONFIGURE_ARGS+=--disable-hal
PLIST_SUB+=	HAL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/gconf/Makefile.in

.include <bsd.port.post.mk>
