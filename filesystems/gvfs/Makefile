PORTNAME=	gvfs
DISTVERSION=	1.56.1
PORTREVISION=	1
CATEGORIES=	filesystems devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system
WWW=		https://www.gnome.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libdbus-1.so:devel/dbus \
		libgcr-4.so:security/gcr \
		libsoup-3.0.so:devel/libsoup3 \
		libgudev-1.0.so:devel/libgudev \
		libudisks2.so:sysutils/libudisks \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	bsdisks>0:sysutils/bsdisks \
		lsof:sysutils/lsof

USES=		cpe gettext gnome libarchive localbase meson \
		pkgconfig python:build tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	glib20 libxml2 libxslt:build
GLIB_SCHEMAS=	org.gnome.system.gvfs.enums.xml
MESON_ARGS=	-Dsystemduserunitdir=no \
		-Dtmpfilesdir=no \
		-Dadmin=false \
		-Dlogind=false \
		-Dlibusb=false \
		-Dman=true

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	AFC AVAHI BLURAY CDDA FUSE GOA GOOGLE GPHOTO MTP NFS ONEDRIVE SMB
OPTIONS_DEFAULT=	AVAHI SMB CDDA GPHOTO MTP NFS BLURAY
OPTIONS_EXCLUDE=	ONEDRIVE
OPTIONS_SUB=	yes

AFC_DESC=	Apple device support
BLURAY_DESC=	Blu-ray metadata support
GOA_DESC=	GNOME Online Accounts volume monitor support
GOOGLE_DESC=	Google backend
ONEDRIVE_DESC=	OneDrive backend

AFC_LIB_DEPENDS=	libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
AFC_MESON_TRUE=		afc

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_MESON_TRUE=	dnssd
AVAHI_VARS=		GLIB_SCHEMAS+=org.gnome.system.dns_sd.gschema.xml

BLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
BLURAY_MESON_TRUE=	bluray

CDDA_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia \
			libcdio.so:sysutils/libcdio
CDDA_MESON_TRUE=	cdda

FUSE_USES=		fuse:3
FUSE_MESON_TRUE=	fuse

GOA_LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts
GOA_MESON_TRUE=		goa

GOOGLE_IMPLIES=		GOA
GOOGLE_LIB_DEPENDS=	libgdata.so:devel/libgdata
GOOGLE_MESON_TRUE=	google

GPHOTO_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO_MESON_TRUE=	gphoto2

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_MESON_TRUE=		mtp

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_MESON_TRUE=		nfs

ONEDRIVE_IMPLIES=	GOA
ONEDRIVE_LIB_DEPENDS=	libmsgraph-1.so:net/msgraph
ONEDRIVE_MESON_TRUE=	onedrive

SMB_USES=		samba:lib
SMB_MESON_TRUE=		smb
SMB_VARS=		GLIB_SCHEMAS+=org.gnome.system.smb.gschema.xml

.include <bsd.port.mk>
