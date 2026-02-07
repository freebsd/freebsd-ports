PORTNAME=	xfce4-generic-slider
PORTVERSION=	1.1.0
PORTEPOCH=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Slider plugin to adjust and/or monitor any numeric variable
WWW=		https://docs.xfce.org/panel-plugins/xfce4-generic-slider/start

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz xfce
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
