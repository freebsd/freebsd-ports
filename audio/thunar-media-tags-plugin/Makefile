PORTNAME=	thunar-media-tags-plugin
PORTVERSION=	0.6.0
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/thunar-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Media tags plugin
WWW=		https://docs.xfce.org/xfce/thunar/media-tags

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	glib20 gtk30
USE_XFCE=	libutil thunar

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
