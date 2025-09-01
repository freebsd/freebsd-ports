PORTNAME=	metronome
DISTVERSION=	1.3.0
PORTREVISION=	20
CATEGORIES=	audio gnome
PKGNAMEPREFIX=	gnome-
DIST_SUBDIR=	gnome

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Keep the tempo
WWW=		https://gitlab.gnome.org/World/metronome

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo gettext-tools gnome gstreamer meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
USE_GNOME=	gtk40 libadwaita
GLIB_SCHEMAS=	com.adrienplazas.Metronome.gschema.xml
USE_GSTREAMER=	bad good vorbis

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

PORTSCOUT=	skipv:2.0.0

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
