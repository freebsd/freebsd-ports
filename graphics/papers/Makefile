PORTNAME=	papers
DISTVERSION=	48.9
PORTREVISION=	2
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	View multipage documents
WWW=		https://gitlab.gnome.org/GNOME/Incubator/papers

LICENSE=	GPLv2+

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		appstreamcli:devel/appstream
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libtiff.so:graphics/tiff \
		libexempi.so:textproc/exempi \
		libgraphene-1.0.so:graphics/graphene \
		libspelling-1.so:x11-toolkits/libspelling \
		libgtksourceview-5.so:x11-toolkits/gtksourceview5
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		cargo desktop-file-utils gettext-tools gnome libarchive \
		localbase:ldflags meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 introspection:build libadwaita
GLIB_SCHEMAS=	org.gnome.Papers.gschema.xml
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddocumentation=false \
		-Duser_doc=false \
		-Dsysprof=disabled \
		-Dtiff=enabled

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

PORTSCOUT=	limit:^48\.

PLIST_SUB=	VERSION=4.0

OPTIONS_DEFINE=		COMICS DJVU KEYRING NAUTILUS
OPTIONS_DEFAULT=	COMICS KEYRING NAUTILUS
OPTIONS_SUB=		yes

COMICS_DESC=		Comic book archives support
DJVU_DESC=		DJVU support
KEYRING_DESC=		Keyring support
NAUTILUS_DESC=		Nautilus (file manager) support

COMICS_MESON_ENABLED=	comics

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_ENABLED=	djvu

KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
KEYRING_MESON_ENABLED=	keyring

NAUTILUS_USE=		gnome=nautilus4
NAUTILUS_MESON_TRUE=	nautilus

.include <bsd.port.mk>
