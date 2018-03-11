# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	appstream-glib
PORTVERSION=	0.5.7
CATEGORIES=	devel
#MASTER_SITES=	http://people.freedesktop.org/~hughsient/appstream-glib/releases/
MASTER_SITES=	http://rainbow-runner.nl/freebsd/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to help with AppStream metadata

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc \
		gcab:archivers/gcab
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libyaml.so:textproc/libyaml \
		libuuid.so:misc/e2fsprogs-libuuid \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	gcab:archivers/gcab

USES=		gettext gperf gmake gnome libarchive libtool pathfix \
		pkgconfig sqlite tar:xz
USE_GNOME=	gdkpixbuf2 glib20 gtk30 intlhack introspection:build \
		libxml2:build pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-xml-catalog=${LOCALBASE}/share/xml/catalog \
		--disable-rpm \
		--disable-ostree
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes
MANPAGES_CONFIGURE_ENABLE=	man
MANPAGES_BUILD_DEPENDS=	docbook-xml>=0:textproc/docbook-xml \
		docbook-xsl>=0:textproc/docbook-xsl
MANPAGES_USE=	GNOME=libxslt:build

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
post-patch:
	@${REINPLACE_CMD} -e 's|-Wtype-limits||g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
