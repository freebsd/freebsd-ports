PORTNAME=	mousai
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.7
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Identify songs in seconds
WWW=		https://github.com/SeaDve/Mousai

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libgraphene-1.0.so:graphics/graphene

USES=		cargo gettext gnome gstreamer meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk40 libadwaita
USE_GSTREAMER=	bad good ogg opus pulse
GH_ACCOUNT=	SeaDve
GH_PROJECT=	Mousai
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	io.github.seadve.Mousai.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		-e "/cp/s,'src',& / '${CARGO_BUILD_TARGET}'," \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
