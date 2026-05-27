PORTNAME=	engrampa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.28.2
CATEGORIES=	archivers mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Archive manager for zip files, tar, etc
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		autoconf-archive>=0:devel/autoconf-archive \
		yelp-tools>=0:textproc/yelp-tools
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	${LOCALBASE}/bin/gtar:archivers/gtar \
		${LOCALBASE}/bin/unzip:archivers/unzip

PORTSCOUT=	limitw:1,even

USE_GITHUB=	yes
GH_ACCOUNT=	mate-desktop
GH_TUPLE=	mate-desktop:mate-submodules:54fff1b:submodules/mate-submodules
USES=		autoreconf desktop-file-utils gettext gmake gnome libtool localbase \
		mate pkgconfig
USE_MATE=	caja common:build
USE_GNOME=	cairo gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-packagekit
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.engrampa.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

.include <bsd.port.mk>
