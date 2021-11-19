PORTNAME=	gnome-pomodoro
PORTVERSION=	0.20.0
CATEGORIES=	deskutils gnome

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Time management utility for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		valac:lang/vala
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libgom-1.0.so:databases/gom \
		libpeas-1.0.so:devel/libpeas

USES=		desktop-file-utils gettext-tools gmake gnome libtool meson \
		pkgconfig sqlite

USE_GITHUB=	yes

# clang fails to compile a C source (gnome-shell-extension.c) generated
# from vala source. USE_GCC=yes is a temporary workaround to this issue.
USE_GCC=	yes
USE_GNOME=	cairo glib20 gtk30 introspection
USE_GSTREAMER1=	yes

GLIB_SCHEMAS=	org.gnome.pomodoro.gschema.xml \
		org.gnome.pomodoro.plugins.actions.gschema.xml \
		org.gnome.pomodoro.plugins.gnome.gschema.xml \
		org.gnome.pomodoro.plugins.sounds.gschema.xml

PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
