PORTNAME=	AppStream
DISTVERSION=	0.15.2
CATEGORIES=	devel
MASTER_SITES=	https://www.freedesktop.org/software/${PORTNAME:tl}/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Machine-readable software metadata for desktop environments

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		gperf>0:devel/gperf \
		itstool:textproc/itstool \
		lmdb>0:databases/lmdb \
		valac:lang/vala
LIB_DEPENDS=	libcurl.so:ftp/curl \
		liblmdb.so:databases/lmdb \
		libstemmer.so:textproc/snowballstemmer \
		libxmlb.so:textproc/libxmlb \
		libyaml.so:textproc/libyaml

USES=		gettext gnome localbase:ldflags meson pkgconfig \
		python:3.6+,build tar:xz

USE_GNOME=	glib20 introspection:build libxml2 libxslt

MESON_ARGS=	-Dstemming=true \
		-Dvapi=true \
		-Dapidocs=false \
		-Dinstall-docs=false

.include <bsd.port.mk>
