# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gvfs
PORTVERSION=	1.30.4
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsoup-2.4.so:devel/libsoup \
		libgcrypt.so:security/libgcrypt \
		libgcr-base-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit \
		libgpg-error.so:security/libgpg-error \
		libcdio.so:sysutils/libcdio \
		libjson-glib-1.0.so:devel/json-glib
PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libarchive libtool localbase \
		pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intlhack libxslt:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-bluray \
		--disable-gudev \
		--disable-libsystemd-login \
		--disable-udisks2 \
		--disable-gdu \
		--disable-udev \
		--disable-goa \
		--disable-libmtp \
		--disable-gtk \
		--disable-libsystemd-login \
		--disable-admin

INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.system.gvfs.enums.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI SAMBA GPHOTO2 CDDA HAL FUSE AFC GOOGLE
OPTIONS_DEFAULT=AVAHI SAMBA GPHOTO2 CDDA HAL FUSE GOOGLE
CDDA_DESC=	CDDA (enables HAL)
GPHOTO2_DESC=	Gphoto 2 camera support (enables HAL) for PTP support
SAMBA_DESC=	Samba support
AFC_DESC=	Apple device support
GOOGLE_DESC=	Google backend

FUSE_USES=	fuse
FUSE_CONFIGURE_ENABLE=	fuse

SAMBA_USES=	samba:lib
SAMBA_CONFIGURE_ENABLE=	samba
SAMBA_CONFIGURE_WITH=	samba-includes=${SAMBAINCLUDES} samba-libs=${SAMBALIBS}

CDDA_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia
CDDA_CONFIGURE_ENABLE=	cdda

GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO2_CONFIGURE_ENABLE=	gphoto2

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

AFC_LIB_DEPENDS=	libimobiledevice.so:comms/libimobiledevice \
			libplist.so:devel/libplist
AFC_CONFIGURE_ENABLE=	afc

GOOGLE_CONFIGURE_ENABLE=	google
GOOGLE_LIB_DEPENDS=	libgdata.so:devel/libgdata \
			libgoa-1.0.so:net/gnome-online-accounts

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSAMBA}
GLIB_SCHEMAS+=	org.gnome.system.smb.gschema.xml
.endif

.if ${PORT_OPTIONS:MAVAHI}
GLIB_SCHEMAS+=	org.gnome.system.dns_sd.gschema.xml
.endif

.if ${PORT_OPTIONS:MHAL} || ${PORT_OPTIONS:MGPHOTO2} || ${PORT_OPTIONS:MCDDA}
LIB_DEPENDS+=	libhal.so:sysutils/hal
RUN_DEPENDS+=	gnome-mount:sysutils/gnome-mount
PLIST_SUB+=	HAL=""
.else
CONFIGURE_ARGS+=--disable-hal
PLIST_SUB+=	HAL="@comment "
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/remote-volume-monitors
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
