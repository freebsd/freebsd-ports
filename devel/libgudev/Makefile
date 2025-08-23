PORTNAME=	libgudev
PORTVERSION=	237
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	x11@FreeBSD.org
COMMENT=	GObject bindings for libudev
WWW=		https://wiki.gnome.org/Projects/libgudev

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		gettext-runtime gnome meson pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

MESON_ARGS=	-Dintrospection=enabled -Dtests=disabled

DOCSDIR=	${PREFIX}/share/gtk-doc/html/${PORTNAME}

OPTIONS_DEFINE=	DOCS VALA
OPTIONS_SUB=	yes

DOCS_MESON_TRUE=	gtk_doc
DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc

VALA_DESC=		Build and install Vala bindings
VALA_MESON_ENABLED=	vapi
VALA_USES=		vala:build

post-patch:
	@${REINPLACE_CMD} -e 's|-export-dynamic|-Wl,--export-dynamic|' ${WRKSRC}/gudev/meson.build

add-plist-docs: ${STAGE_COOKIE}
	cd ${STAGEDIR}; ${FIND} ${DOCSDIR:C@^/@@} -type f | ${SED} -e 's@^@/@' >> ${TMPPLIST}
	cd ${STAGEDIR}; ${FIND} ${LOCALBASE:C@^/@@}/share/gtk-doc/html -mindepth 2 -type f | ${SED} -e 's@^@/@' >> ${TMPPLIST}

.include <bsd.port.mk>
