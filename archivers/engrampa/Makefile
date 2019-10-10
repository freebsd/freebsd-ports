# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	engrampa
PORTVERSION=	1.22.1
CATEGORIES=	archivers mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Archive manager for zip files, tar, etc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	${LOCALBASE}/bin/gtar:archivers/gtar \
		${LOCALBASE}/bin/unzip:archivers/unzip

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool localbase \
		mate pathfix pkgconfig tar:xz
USE_MATE=	caja
USE_GNOME=	cairo gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-packagekit
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.engrampa.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

.include <bsd.port.mk>
