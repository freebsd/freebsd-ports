# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gvfs
PORTVERSION=	1.46.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libdbus-1.so:devel/dbus \
		libgcr-base-3.so:security/gcr \
		libsoup-2.4.so:devel/libsoup \
		libgudev-1.0.so:devel/libgudev \
		libudisks2.so:sysutils/libudisks \
		libsecret-1.so:security/libsecret \
		libbluray.so:multimedia/libbluray
RUN_DEPENDS=	bsdisks>0:sysutils/bsdisks
PORTSCOUT=	limitw:1,even

USES=		gettext gnome libarchive localbase meson \
		pkgconfig python:3.5+,build shebangfix tar:xz
USE_GNOME=	glib20 libxml2 libxslt:build
SHEBANG_FILES=	meson_post_install.py
MESON_ARGS=	-Dsystemduserunitdir=no \
		-Dtmpfilesdir=no \
		-Dadmin=false \
		-Dlogind=false \
		-Dlibusb=false \
		-Dman=true
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.system.gvfs.enums.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI FUSE AFC GOA SAMBA CDDA GOOGLE GPHOTO2 MTP NFS
OPTIONS_DEFAULT=AVAHI FUSE GOA SAMBA CDDA GOOGLE GPHOTO2 MTP NFS
AFC_DESC=	Apple device support
GOA_DESC=	GNOME Online Accounts volume monitor support
GOOGLE_DESC=	Google backend

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_MESON_TRUE=	dnssd
AVAHI_VARS=		GLIB_SCHEMAS+=org.gnome.system.dns_sd.gschema.xml

FUSE_USES=		fuse:3
FUSE_MESON_TRUE=	fuse

AFC_LIB_DEPENDS=	libimobiledevice.so:comms/libimobiledevice \
			libplist.so:devel/libplist
AFC_MESON_TRUE=		afc

GOA_LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts
GOA_MESON_TRUE=		goa

SAMBA_USES=		samba:lib
SAMBA_MESON_TRUE=		smb
SAMBA_VARS=		GLIB_SCHEMAS+=org.gnome.system.smb.gschema.xml

CDDA_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia \
			libcdio.so:sysutils/libcdio
CDDA_MESON_TRUE=	cdda

GOOGLE_IMPLIES=		GOA
GOOGLE_LIB_DEPENDS=	libgdata.so:devel/libgdata
GOOGLE_MESON_TRUE=	google

GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO2_MESON_TRUE=	gphoto2

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_MESON_TRUE=		mtp

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_MESON_TRUE=		nfs

.include <bsd.port.mk>

