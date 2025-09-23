PORTNAME=	gnome-pomodoro
PORTVERSION=	0.28.0
PORTEPOCH=	1
CATEGORIES=	deskutils gnome

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Time management utility for GNOME
WWW=		https://gnomepomodoro.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libgom-1.0.so:databases/gom \
		libpeas-1.0.so:devel/libpeas1

USES=		desktop-file-utils gettext-tools gmake gnome gstreamer libtool \
		meson pkgconfig sqlite vala:build

USE_GITHUB=	yes

USE_GNOME=	cairo glib20 gtk30 introspection

GLIB_SCHEMAS=	org.gnome.pomodoro.gschema.xml \
		org.gnome.pomodoro.plugins.actions.gschema.xml \
		org.gnome.pomodoro.plugins.gnome.gschema.xml \
		org.gnome.pomodoro.plugins.sounds.gschema.xml

PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
