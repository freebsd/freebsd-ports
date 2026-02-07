PORTNAME=	xfmpc
PORTVERSION=	0.4.0
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Graphical MPD client focusing on low footprint
WWW=		https://gitlab.xfce.org/apps/xfmpc

LICENSE=	GPLv2

LIB_DEPENDS=	libmpd.so:audio/libmpd

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz \
		vala:build xfce xorg
USE_GNOME=	gtk30
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
