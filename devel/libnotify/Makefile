PORTNAME=	libnotify
DISTVERSION=	0.8.7
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for desktop notifications
WWW=		https://gitlab.gnome.org/GNOME/libnotify

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	gdkpixbuf glib20 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddocbook_docs=disabled \
		-Dgtk_doc=false \
		-Dtests=false

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			docbook-xsl-ns>0:textproc/docbook-xsl-ns
MANPAGES_USE=		GNOME=libxslt:build
MANPAGES_MESON_TRUE=	man

.include <bsd.port.mk>
