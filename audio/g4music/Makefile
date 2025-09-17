PORTNAME=	g4music
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5
CATEGORIES=	audio

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Play music elegantly
WWW=		https://gitlab.gnome.org/neithern/g4music

LICENSE=	GPLv3

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene
RUN_DEPENDS=	dbus>0:devel/dbus

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig tar:bz2 vala:build
USE_GNOME=	gdkpixbuf glib20 gtk40 libadwaita
USE_GSTREAMER=	good faad flac lame libav ogg opus pulse taglib vorbis wavpack

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	neithern

GLIB_SCHEMAS=	com.github.neithern.g4music.gschema.xml \
		05_org.gnome.gitlab.neithern.g4music.gschema.override

post-extract:
	${CP} ${FILESDIR}/05_org.gnome.gitlab.neithern.g4music.gschema.override \
		${WRKSRC}/data/

.include <bsd.port.mk>
