PORTNAME=	amberol
DISTVERSION=	2025.1
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plays music, and nothing else
WWW=		https://gitlab.gnome.org/World/amberol

LICENSE=	CC-BY-SA-3.0 CC0-1.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/LICENSES/CC-BY-SA-3.0.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgraphene-1.0.so:graphics/graphene

USES=		cargo desktop-file-utils gettext gnome gstreamer meson \
		pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
USE_GNOME=	gdkpixbuf gtk40 libadwaita
GLIB_SCHEMAS=	io.bassi.Amberol.gschema.xml
USE_GSTREAMER=	bad good libav

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
