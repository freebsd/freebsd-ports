PORTNAME=	thunar-archive-plugin
PORTVERSION=	0.6.0
CATEGORIES=	archivers xfce
MASTER_SITES=	XFCE/thunar-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Archive plugin for the Thunar File Manager
WWW=		https://docs.xfce.org/xfce/thunar/archive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	gtk30
USE_XFCE=	libexo thunar

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
