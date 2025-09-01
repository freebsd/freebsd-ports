PORTNAME=	solanum
DISTVERSION=	5.0.0
PORTREVISION=	16
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pomodoro timer for the GNOME desktop
WWW=		https://gitlab.gnome.org/World/Solanum

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler

USES=		cargo gettext gnome gstreamer meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER=	bad good vorbis
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Solanum
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	org.gnome.Solanum.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
