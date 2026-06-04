PORTNAME=	amberol
DISTVERSION=	2026.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Plays music, and nothing else
WWW=		https://gitlab.gnome.org/World/amberol

LICENSE=	CC-BY-SA-3.0 CC0-1.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/LICENSES/CC-BY-SA-3.0.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	blueprint-compiler>0:devel/blueprint-compiler
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene
TEST_DEPENDS=	bash>0:shells/bash

USES=		cargo desktop-file-utils gettext gnome gstreamer meson \
		pkgconfig shebangfix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
USE_GNOME=	gdkpixbuf gtk40 libadwaita
GLIB_SCHEMAS=	io.bassi.Amberol.gschema.xml
USE_GSTREAMER=	bad good libav
SHEBANG_FILES=	build-aux/checks.sh

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} meson test --print-errorlogs --no-rebuild

.include <bsd.port.mk>
