PORTNAME=	libosinfo
DISTVERSION=	1.12.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/${PORTNAME}/

PATCH_SITES=	https://gitlab.com/libosinfo/libosinfo/-/commit/
PATCHFILES+=	0adf385.patch:-p1

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for managing OS information for virtualization
WWW=		https://libosinfo.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup
BUILD_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids
RUN_DEPENDS=	${BUILD_DEPENDS} \
		osinfo-db-import:sysutils/osinfo-db-tools \
		${LOCALBASE}/share/osinfo/VERSION:misc/osinfo-db

USES=		gettext gnome meson perl5 pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2 libxslt introspection:build
USE_PERL5=	build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dlibsoup-abi=2.4 \
		-Denable-vala=disabled \
		-Dwith-usb-ids-path=${LOCALBASE}/share/usbids/usb.ids \
		-Dwith-pci-ids-path=${LOCALBASE}/share/pciids/pci.ids

SHLIB_VER=	0.1012.0
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}

OPTIONS_DEFINE=	GTKDOC
OPTIONS_DEFAULT=GTKDOC
OPTIONS_SUB=	yes

GTKDOC_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
GTKDOC_MESON_TRUE=	enable-gtk-doc

.include <bsd.port.mk>
