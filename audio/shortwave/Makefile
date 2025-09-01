PORTNAME=	shortwave
DISTVERSION=	5.0.0
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Listen to internet radio
WWW=		https://gitlab.gnome.org/World/Shortwave

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libshumate-1.0.so:x11-toolkits/libshumate

USES=		cargo desktop-file-utils gettext gnome gstreamer meson pkgconfig sqlite ssl
USE_GITLAB=	yes
USE_GNOME=	gdkpixbuf gtk40 libadwaita
USE_GSTREAMER=	good libav soup vorbis
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Shortwave
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	de.haeckerfelix.Shortwave.gschema.xml

OPTIONS_DEFINE=	PULSEAUDIO
OPTIONS_DEFAULT=PULSEAUDIO

PULSEAUDIO_USE=	GSTREAMER=pulse

post-patch:
	@${REINPLACE_CMD} -e '/gstreamer.*bad/d' \
		-e "/vcs_tag/s/=.*/= '${DISTVERSIONFULL}'/" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
