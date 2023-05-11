PORTNAME=	metronome
DISTVERSION=	1.2.1
CATEGORIES=	audio
PKGNAMEPREFIX=	gnome-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Keep the tempo
WWW=		https://gitlab.gnome.org/World/metronome

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo gettext gnome gstreamer meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER=	bad good vorbis
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_COMMIT=	1a9f4b1bebcd6a6fb76c1774714e43006de8d503
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	com.adrienplazas.Metronome.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		-e "/cp/s,'src',& / '${CARGO_BUILD_TARGET}'," \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
