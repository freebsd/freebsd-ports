PORTNAME=	podcasts
DISTVERSION=	0.7.1
PORTREVISION=	12
CATEGORIES=	audio
PKGNAMEPREFIX=	gnome-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Podcast app for GNOME
WWW=		https://gitlab.gnome.org/World/podcasts

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		cargo gettext gnome gstreamer meson pkgconfig sqlite ssl
USE_GITLAB=	yes
USE_GNOME=	gdkpixbuf gtk40 libadwaita
USE_GSTREAMER=	bad good libav
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	org.gnome.Podcasts.gschema.xml

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH:Marmv?}
# https://github.com/rust-lang/rust/issues/85598
LTO_UNSAFE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/dependency.*openssl/d' \
		-e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/${PORTNAME}-gtk/src/meson.build

.include <bsd.port.mk>
