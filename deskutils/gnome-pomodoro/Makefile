PORTNAME=	gnome-pomodoro
PORTVERSION=	0.18.0
CATEGORIES=	deskutils gnome

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Time management utility for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		autoconf-archive>0:devel/autoconf-archive \
		valac:lang/vala
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libgom-1.0.so:databases/gom \
		libpeas-1.0.so:devel/libpeas

USES=		autoreconf desktop-file-utils gettext-tools gmake gnome \
		libtool pkgconfig sqlite

USE_GITHUB=	yes

GNU_CONFIGURE=	yes

# clang fails to compile a C source (gnome-shell-extension.c) generated
# from vala source. USE_GCC=yes is a temporary workaround to this issue.
USE_GCC=	yes
USE_GNOME=	cairo glib20 gtk30 introspection
USE_GSTREAMER1=	yes

INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.pomodoro.gschema.xml \
		org.gnome.pomodoro.plugins.actions.gschema.xml \
		org.gnome.pomodoro.plugins.gnome.gschema.xml \
		org.gnome.pomodoro.plugins.sounds.gschema.xml
INSTALLS_ICONS=	yes

PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
