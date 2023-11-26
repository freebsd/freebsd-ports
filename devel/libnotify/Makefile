PORTNAME=	libnotify
DISTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for desktop notifications
WWW=		https://gitlab.gnome.org/GNOME/libnotify

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl-ns>=0:textproc/docbook-xsl-ns

USES=		gmake gnome libtool meson pkgconfig tar:xz
USE_GNOME=	glib20 gdkpixbuf2 introspection:build libxslt:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dtests=false -Ddocbook_docs=disabled -Dgtk_doc=false

post-patch:
	${REINPLACE_CMD} -e "s#http:.*docbook.xsl#${LOCALBASE}/share/xsl/docbook-ns/manpages/docbook.xsl#g" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
