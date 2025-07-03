PORTNAME=	mousai
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.8
PORTREVISION=	7
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Identify songs in seconds
WWW=		https://github.com/SeaDve/Mousai

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libsoup-3.0.so:devel/libsoup3

USES=		cargo gettext gnome gstreamer meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	SeaDve
GH_PROJECT=	Mousai
USE_GNOME=	cairo gtk40 libadwaita
GLIB_SCHEMAS=	io.github.seadve.Mousai.gschema.xml
USE_GSTREAMER=	bad good ogg opus pulse

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
