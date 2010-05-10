# New ports collection makefile for:	gvfs
# Date created:		2007-11-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gvfs/Makefile,v 1.61 2010/04/26 12:09:46 kwm Exp $
#

PORTNAME=	gvfs
PORTVERSION=	1.6.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
    		hal.1:${PORTSDIR}/sysutils/hal \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring \
		avahi-client.3:${PORTSDIR}/net/avahi-app
RUN_DEPENDS=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount

USE_BZIP2=	yes
USE_GNOME=	glib20 gnomehack gnomeprefix intlhack gconf2
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-obexftp
OPTIONS=	FUSE "Enable fuse" off \
		SAMBA "Enable Samba" on \
		GPHOTO2 "Enable Gphoto 2 camera support" on \
		CDDA "Enable CDDA" on

.include <bsd.port.pre.mk>

.if defined(WITH_FUSE)
LIB_DEPENDS+=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS+=	mount_fusefs:${PORTSDIR}/sysutils/fusefs-kmod
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

.if defined(WITH_CDDA)
LIB_DEPENDS+=	cdio_paranoia.0:${PORTSDIR}/sysutils/libcdio
PLIST_SUB+=	CDDA=""
.else
CONFIGURE_ARGS+=	--disable-cdda
PLIST_SUB+=	CDDA="@comment "
.endif

.if defined(WITH_GPHOTO2)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
PLIST_SUB+=	GPHOTO2=""
.else
CONFIGURE_ARGS+=	--disable-gphoto2
PLIST_SUB+=	GPHOTO2="@comment "
.endif

.if ${OSVERSION} < 602112
CONFIGURE_ARGS+=	--disable-archive
PLIST_SUB+=	ARCHIVE="@comment "
.else
PLIST_SUB+=	ARCHIVE=""
.endif

.include <bsd.port.post.mk>
