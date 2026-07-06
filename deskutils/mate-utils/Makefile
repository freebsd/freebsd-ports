PORTNAME=	mate-utils
DISTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	deskutils mate
MASTER_SITES=	https://github.com/mate-desktop/${PORTNAME}/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE support utilities
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2+ GFDL LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING.docs
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.libs

BUILD_DEPENDS=	itstool:textproc/itstool

LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libudisks2.so:sysutils/libudisks

USES=		gettext gmake gnome libtool localbase mate \
		pkgconfig tar:xz xorg
USE_MATE=	panel common:build
USE_XORG=	ice sm x11 xext
USE_GNOME=	cairo gnomeprefix gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

PORTSCOUT=	site:https://github.com/mate-desktop/mate-utils/releases/ limitw:1,even

GLIB_SCHEMAS=	org.mate.dictionary.gschema.xml \
		org.mate.disk-usage-analyzer.gschema.xml \
		org.mate.screenshot.gschema.xml \
		org.mate.search-tool.gschema.xml \
		org.mate.system-log.gschema.xml

.include <bsd.port.mk>
