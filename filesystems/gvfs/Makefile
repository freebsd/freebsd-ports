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
PORTSCOUT=	limitw:1,even

USES=		cpe gettext gnome libarchive localbase meson \
		pkgconfig python:build tar:xz
USE_GNOME=	glib20 libxml2 libxslt:build
MESON_ARGS=	-Dsystemduserunitdir=no \
		-Dtmpfilesdir=no \
		-Dadmin=false \
		-Dlogind=false \
		-Dlibusb=false \
		-Dman=true
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.system.gvfs.enums.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI FUSE AFC GOA SMB CDDA GOOGLE GPHOTO MTP NFS BLURAY
OPTIONS_DEFAULT=AVAHI SMB CDDA GPHOTO MTP NFS BLURAY

AFC_DESC=	Apple device support
GOA_DESC=	GNOME Online Accounts volume monitor support
GOOGLE_DESC=	Google backend

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_MESON_TRUE=	dnssd
AVAHI_VARS=		GLIB_SCHEMAS+=org.gnome.system.dns_sd.gschema.xml

BLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
BLURAY_MESON_TRUE=	bluray
BLURAY_DESC=		Blu-ray metadata support

FUSE_USES=		fuse:3
FUSE_MESON_TRUE=	fuse

AFC_LIB_DEPENDS=	libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
AFC_MESON_TRUE=		afc

GOA_LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts \
			libmsgraph-0.so:net/msgraph
GOA_MESON_TRUE=		goa onedrive

SMB_USES=		samba:lib
SMB_MESON_TRUE=		smb
SMB_VARS=		GLIB_SCHEMAS+=org.gnome.system.smb.gschema.xml

CDDA_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia \
			libcdio.so:sysutils/libcdio
CDDA_MESON_TRUE=	cdda

GOOGLE_IMPLIES=		GOA
GOOGLE_LIB_DEPENDS=	libgdata.so:devel/libgdata
GOOGLE_MESON_TRUE=	google

GPHOTO_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO_MESON_TRUE=	gphoto2

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_MESON_TRUE=		mtp

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_MESON_TRUE=		nfs

.include <bsd.port.mk>
