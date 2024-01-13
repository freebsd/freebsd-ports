# Some knobs are defined with ?= and += to allow them
# being overriden by devel/appstream-qt slave port

PORTNAME?=	AppStream
DISTVERSION=	1.0.0
PORTREVISION?=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.freedesktop.org/software/${PORTNAME:tl}/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	Machine-readable software metadata for desktop environments
WWW=		https://www.freedesktop.org/wiki/Distributions/AppStream/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

SUBPACKAGES?=	compose qt6

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		gperf>0:devel/gperf \
		itstool:textproc/itstool \
		lmdb>0:databases/lmdb
LIB_DEPENDS?=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libstemmer.so:textproc/snowballstemmer \
		libxmlb.so:textproc/libxmlb \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd
SELF_DEPENDS.compose=	main
SELF_DEPENDS.qt6=	main

USES=		gettext gnome localbase:ldflags meson pkgconfig \
		qt:${QT_FLAVOR} tar:xz python:build vala:build

USE_QT=		${_USE_QT_${QT_FLAVOR}}
USE_GNOME=	cairo gdkpixbuf2 glib20 introspection:build librsvg2 libxml2 \
		libxslt:build pango
USE_LDCONFIG=	yes

QT_FLAVOR?=	6
_USE_QT_5=	core buildtools:build qmake:build testlib:build
_USE_QT_6=	base

#CFLAGS+=	-D__BSD_VISIBLE=1
MESON_ARGS+=	-Dcompose=true \
		-Dstemming=true \
		-Dvapi=true \
		-Dapidocs=false \
		-Dinstall-docs=false \
		-Dsystemd=false \
		${_MESON_ARGS_qt${QT_FLAVOR}}

_MESON_ARGS_qt5=	-Dqt5=true
_MESON_ARGS_qt6=	-Dqt=true

post-patch:
	${REINPLACE_CMD} \
		-e 's|APPLICATIONS_DIR = "/usr/share/applications"|APPLICATIONS_DIR = "${LOCALBASE}/share/applications"|' \
		-e 's|METAINFO_DIR = "/usr/share/metainfo"|METAINFO_DIR = "${LOCALBASE}/share/metainfo"|' \
		-e 's|"/usr/share",|"${LOCALBASE}/share",|' \
		${WRKSRC}/src/as-pool.c
	${REINPLACE_CMD} \
		-e 's|"/usr/share";|"${LOCALBASE}/share";|' \
		${WRKSRC}/src/as-utils.c

.include <bsd.port.mk>
