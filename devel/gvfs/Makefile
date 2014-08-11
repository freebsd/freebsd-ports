# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD: head/devel/gvfs/Makefile 353795 2014-05-12 10:28:51Z tijl $
#   $MCom: ports/trunk/devel/gvfs/Makefile 19796 2014-08-09 11:01:25Z kwm $

PORTNAME=	gvfs
PORTVERSION=	1.20.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix intlhack intltool libxslt:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-obexftp \
		--disable-bluray \
		--disable-afc

CONFIGURE_ARGS+=\
		--disable-gudev \
		--disable-libsystemd-login \
		--disable-udisks2 \
		--disable-gdu \
		--disable-udev \
		--disable-goa \
		--disable-keyring \
		--disable-bluray \
		--disable-libmtp \
		--disable-gtk

INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.system.gvfs.enums.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI SAMBA GPHOTO2 CDDA HAL FUSE
OPTIONS_DEFAULT=AVAHI SAMBA GPHOTO2 CDDA HAL FUSE
CDDA_DESC=	CDDA (enables HAL)
GPHOTO2_DESC=	Gphoto 2 camera support (enables HAL)
SAMBA_DESC=	Samba support

FUSE_USES=	fuse
FUSE_CONFIGURE_ENABLE=	fuse

SAMBA_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SAMBA_CONFIGURE_ENABLE=	samba

CDDA_LIB_DEPENDS=	libcdio_paranoia.so:${PORTSDIR}/sysutils/libcdio-paranoia
CDDA_CONFIGURE_ENABLE=	cdda

GPHOTO2_LIB_DEPENDS=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2
GPHOTO2_CONFIGURE_ENABLE=	gphoto2

AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSAMBA}
GLIB_SCHEMAS+=	org.gnome.system.smb.gschema.xml
.endif

.if ${PORT_OPTIONS:MAVAHI}
GLIB_SCHEMAS+=	org.gnome.system.dns_sd.gschema.xml
.endif

.if ${PORT_OPTIONS:MHAL} || ${PORT_OPTIONS:MGPHOTO2} || ${PORT_OPTIONS:MCDDA}
LIB_DEPENDS+=	libhal.so:${PORTSDIR}/sysutils/hal
RUN_DEPENDS+=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount
PLIST_SUB+=	HAL=""
.else
CONFIGURE_ARGS+=--disable-hal
PLIST_SUB+=	HAL="@comment "
.endif

# https://bugzilla.gnome.org/show_bug.cgi?id=722411
post-patch:
	@${RM} ${WRKSRC}/monitor/hal/gvfsdbusutils.[ch]

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/remote-volume-monitors
	${TOUCH} ${STAGEDIR}${DATADIR}/remote-volume-monitors/.keep

.include <bsd.port.mk>
