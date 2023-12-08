PORTNAME=	amberol
DISTVERSION=	0.10.3
PORTREVISION=	5
CATEGORIES=	audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Plays music, and nothing else
WWW=		https://gitlab.gnome.org/World/amberol

LICENSE=	CC0-1.0 CC-BY-SA-3.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/LICENSES/CC-BY-SA-3.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgraphene-1.0.so:graphics/graphene

USES=		cargo desktop-file-utils gettext gnome gstreamer meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	gdkpixbuf2 gtk40 libadwaita
USE_GSTREAMER=	bad good libav
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	io.bassi.Amberol.gschema.xml

post-patch:
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		-e "/cp/s,'src',& / '${CARGO_BUILD_TARGET}'," \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
