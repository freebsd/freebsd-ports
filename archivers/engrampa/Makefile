PORTNAME=	engrampa
DISTVERSION=	1.28.2
PORTREVISION=	1
CATEGORIES=	archivers mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Archive manager for zip files, tar, etc
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	${LOCALBASE}/bin/gtar:archivers/gtar \
		${LOCALBASE}/bin/unzip:archivers/unzip

USES=		desktop-file-utils gettext gmake gnome libtool localbase \
		mate pkgconfig tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_MATE=	caja common:build
USE_GNOME=	cairo gtk30 intltool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-packagekit
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

GLIB_SCHEMAS=	org.mate.engrampa.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

.include <bsd.port.mk>
