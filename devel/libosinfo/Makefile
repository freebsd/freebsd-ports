# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libosinfo
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/l/i/libosinfo/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for managing OS information for virtualization

LIB_DEPENDS=	libsoup-gnome-2.4.so:devel/libsoup-gnome
BUILD_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		osinfo-db-import:sysutils/osinfo-db-tools \
		${LOCALBASE}/share/osinfo/VERSION:misc/osinfo-db

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	glib20 libxml2 libxslt introspection:build intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-tests --disable-vala \
		--with-usb-ids-path=${LOCALBASE}/share/usbids/usb.ids \
		--with-pci-ids-path=${LOCALBASE}/share/pciids/pci.ids
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

SHLIB_VER=	${PORTVERSION:C/(^[0-9])\./0.\100/}
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}

.include <bsd.port.mk>
