PORTNAME=	meteo
PORTVERSION=	0.9.9.3
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Weather forecast application using OpenWeatherMap API
WWW=		https://gitlab.com/bitseater/meteo

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libappindicator3.so:devel/libappindicator \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40

USES=		compiler:c11 gettext gnome meson pkgconfig python:build \
		shebangfix vala:build

USE_GITLAB=	yes
GL_ACCOUNT=	bitseater

USE_GNOME=	gtk30

SHEBANG_FILES=	meson/post_install.py

GLIB_SCHEMAS=	com.gitlab.bitseater.meteo.gschema.xml

PORTDOCS=	AUTHORS CONTRIBUTING.md CREDITS.md README.md changelog

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/debian/changelog ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
