PORTNAME=	mate-media
DISTVERSION=	1.28.1
PORTREVISION=	3
CATEGORIES=	audio mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the MATE desktop
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libstartup-notification-1.so:x11/startup-notification \
		libunique-3.0.so:x11-toolkits/libunique3

USES=		gettext gmake gnome libtool localbase mate pkgconfig tar:xz \
		xorg
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_MATE=	desktop mixer panel
USE_GNOME=	cairo glib20 gtk30 intlhack libxml2
USE_XORG=	x11
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
