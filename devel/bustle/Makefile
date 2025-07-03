PORTNAME=	bustle
DISTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	devel gnome

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Visualize D-Bus activity
WWW=		https://apps.gnome.org/Bustle/ \
		https://gitlab.gnome.org/World/bustle

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstreamcli:devel/appstream
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo desktop-file-utils gettext-tools gnome meson

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World

USE_GNOME=	glib20 gtk40 libadwaita
GLIB_SCHEMAS=	org.freedesktop.Bustle.gschema.xml

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
