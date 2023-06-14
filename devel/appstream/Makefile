# Some knobs are defined with ?= and += to allow them
# being overriden by devel/appstream-qt slave port

PORTNAME?=	AppStream
DISTVERSION=	0.16.1
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	https://www.freedesktop.org/software/${PORTNAME:tl}/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	Machine-readable software metadata for desktop environments
WWW=		https://www.freedesktop.org/wiki/Distributions/AppStream/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		gperf>0:devel/gperf \
		itstool:textproc/itstool \
		lmdb>0:databases/lmdb
LIB_DEPENDS?=	libcurl.so:ftp/curl \
		liblmdb.so:databases/lmdb \
		libstemmer.so:textproc/snowballstemmer \
		libxmlb.so:textproc/libxmlb \
		libyaml.so:textproc/libyaml

USES+=		gettext gnome localbase:ldflags meson pkgconfig \
		python:build tar:xz vala:build

USE_GNOME+=	glib20 introspection:build libxml2 libxslt
USE_LDCONFIG=	yes

CFLAGS+=	-D__BSD_VISIBLE=1
MESON_ARGS+=	-Dstemming=true \
		-Dvapi=true \
		-Dapidocs=false \
		-Dinstall-docs=false \
		-Dsystemd=false

post-patch:
	${REINPLACE_CMD} \
		-e 's|APPLICATIONS_DIR = "/usr/share/applications"|APPLICATIONS_DIR = "${LOCALBASE}/share/applications"|' \
		-e 's|METAINFO_DIR = "/usr/share/metainfo"|METAINFO_DIR = "${LOCALBASE}/share/metainfo"|' \
		-e 's|"/usr/share",|"${LOCALBASE}/share",|' \
		${WRKSRC}/src/as-pool.c
	${REINPLACE_CMD} \
		-e 's|"/usr/share";|"${LOCALBASE}/share";|' \
		${WRKSRC}/src/as-utils.c
	${REINPLACE_CMD} \
		-e 's|"/usr/share/fonts/"|"${LOCALBASE}/share/fonts/"|' \
		${WRKSRC}/compose/asc-utils-fonts.c

.include <bsd.port.mk>
