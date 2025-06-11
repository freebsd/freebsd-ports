PORTNAME=	libspiel
DISTVERSION=	1.0.4
CATEGORIES=	accessibility

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Speech synthesis client library
WWW=		https://project-spiel.org/libspiel/

LICENSE=	LGPL21+

LIB_DEPENDS=	libspeech-provider-1.0.so:accessibility/libspeechprovider

USES=		gnome gstreamer meson pkgconfig python:build
USE_GNOME=	glib20 introspection:build

USE_GITHUB=	yes
GH_ACCOUNT=	project-spiel
GH_TAGNAME=	2ab0230

BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Dtests=false \
		-Ddocs=false

GLIB_SCHEMAS=	org.monotonous.libspiel.gschema.xml

.include <bsd.port.mk>
