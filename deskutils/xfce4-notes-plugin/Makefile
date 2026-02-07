PORTNAME=	xfce4-notes-plugin
PORTVERSION=	1.12.0
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Notes plugin for the Xfce panel
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-notes-plugin

LICENSE=	GPLv2

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz \
		vala:build xfce xorg
USE_GNOME=	glib20 gtk30 gtksourceview4
USE_XFCE=	libmenu panel xfconf
USE_XORG=	ice sm x11

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
