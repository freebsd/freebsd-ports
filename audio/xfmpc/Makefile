PORTNAME=	xfmpc
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Graphical MPD client focusing on low footprint
WWW=		https://goodies.xfce.org/projects/applications/xfmpc

LICENSE=	GPLv2

LIB_DEPENDS=	libmpd.so:audio/libmpd \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig tar:bzip2 \
		vala:build xfce xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
