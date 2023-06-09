PORTNAME=	podcasts
DISTVERSION=	0.5.1
PORTREVISION=	17
CATEGORIES=	audio
PKGNAMEPREFIX=	gnome-

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	6614bb62ecbe.patch:-p1 # https://gitlab.gnome.org/World/podcasts/-/merge_requests/213

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Podcast app for GNOME
WWW=		https://gitlab.gnome.org/World/podcasts

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libhandy-1.so:x11-toolkits/libhandy

USES=		cargo gettext gnome gstreamer meson pkgconfig python:build shebangfix sqlite ssl
USE_GITLAB=	yes
USE_GNOME=	gdkpixbuf2 gtk30
USE_GSTREAMER=	bad good libav
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_COMMIT=	c86f7bfdef7692bbf20f315a90450321f6ca9ce7
SHEBANG_FILES=	scripts/cargo.sh scripts/compile-gschema.py
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	org.gnome.Podcasts.gschema.xml

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LTO_UNSAFE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/dependency.*openssl/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/ARGS=/s/()/('--verbose' '--verbose')/" \
		${WRKSRC}/scripts/cargo.sh

.include <bsd.port.mk>
