PORTNAME=	libspeechprovider
DISTVERSION=	1.0.3
CATEGORIES=	accessibility

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Utility library for creating Spiel speech providers
WWW=		https://project-spiel.org/libspeechprovider/

LICENSE=	APACHE20

USES=		gnome gstreamer meson pkgconfig python:build
USE_GNOME=	glib20 introspection:build

USE_GITHUB=	yes
GH_ACCOUNT=	project-spiel
GH_TAGNAME=	07e6a2a

BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Ddocs=false \
		-Dtests=false

.include <bsd.port.mk>
