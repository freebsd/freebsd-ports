PORTNAME=	meteo
PORTVERSION=	1.0.0
CATEGORIES=	deskutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Weather forecast application using OpenWeatherMap API
WWW=		https://gitlab.com/bitseater/meteo

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstreamcli:devel/appstream
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libsoup-3.0.so:devel/libsoup3 \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60

USES=		compiler:c11 gettext-tools gnome meson pkgconfig vala:build

USE_GITLAB=	yes
GL_ACCOUNT=	bitseater

USE_GNOME=	gtk40 libadwaita

GLIB_SCHEMAS=	com.gitlab.bitseater.meteo.gschema.xml

PORTDOCS=	AUTHORS CONTRIBUTING.md CREDITS.md README.md changelog

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/debian/changelog ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
