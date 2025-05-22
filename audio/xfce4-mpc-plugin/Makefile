PORTNAME=	xfce4-mpc-plugin
PORTVERSION=	0.6.0
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Musicpd client plugin for the Xfce panel
WWW=		https://docs.xfce.org/panel-plugins/xfce4-mpc-plugin/start

LICENSE=	ISCL

LIB_DEPENDS=	libmpd.so:audio/libmpd
RUN_DEPENDS=	musicpd:audio/musicpd

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel

MESON_ARGS=	-Dlibmpd=enabled

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
