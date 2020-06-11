# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libosinfo
PORTVERSION=	1.8.0
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/libosinfo/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for managing OS information for virtualization

LIB_DEPENDS=	libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsoup-2.4.so:devel/libsoup
BUILD_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		osinfo-db-import:sysutils/osinfo-db-tools \
		${LOCALBASE}/share/osinfo/VERSION:misc/osinfo-db

USES=		compiler:c11 gettext gmake gnome libtool pathfix \
		pkgconfig tar:xz meson
USE_GNOME=	glib20 libxml2 libxslt introspection:build intlhack
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=	-Denable-vala=disabled \
			-Dwith-usb-ids-path=${LOCALBASE}/share/usbids/usb.ids \
			-Dwith-pci-ids-path=${LOCALBASE}/share/pciids/pci.ids

SHLIB_VER=	0.1008.0
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}

OPTIONS_DEFINE=	GTKDOC
OPTIONS_DEFAULT=	GTKDOC
OPTIONS_SUB=	yes

GTKDOC_DESC=	Build gtk-doc documentation
GTKDOC_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
GTKDOC_MESON_TRUE=	enable-gtk-doc

.include <bsd.port.mk>
