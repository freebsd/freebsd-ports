PORTNAME=	gnome-video-effects
PORTVERSION=	0.6.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of Gstreamer effects
WWW=		https://wiki.gnome.org/Projects/GnomeVideoEffects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	frei0r>0:graphics/frei0r

USES=		gettext gstreamer meson tar:xz
USE_GSTREAMER=	good bad
NO_ARCH=	yes

.include <bsd.port.mk>
