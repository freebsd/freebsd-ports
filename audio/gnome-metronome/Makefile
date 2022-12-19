PORTNAME=	metronome
DISTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	audio
PKGNAMEPREFIX=	gnome-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Keep the tempo
WWW=		https://gitlab.gnome.org/World/metronome

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo gettext gnome gstreamer meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER=	bad good vorbis
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_COMMIT=	26fb83ff4ca32bf801260c3e32af6dcef19f5e59
SHEBANG_FILES=	build-aux/meson_post_install.py
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	com.adrienplazas.Metronome.gschema.xml

post-patch:
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e '/cargo/s/ --/&verbose&verbose&/' \
		-Ee '/cp/s,/(release|debug)/,/${CARGO_BUILD_TARGET}&,' \
		${WRKSRC}/build-aux/cargo.sh

.include <bsd.port.mk>
