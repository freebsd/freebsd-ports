PORTNAME=	extension-manager
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	deskutils gnome
PKGNAMEPREFIX=	gnome-shell-

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Browse, install, and manage GNOME extensions with ease
WWW=		https://mattjakeman.com/apps/extension-manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstreamcli:devel/appstream \
		blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libbacktrace.so:devel/libbacktrace \
		libsoup-3.0.so:devel/libsoup3 \
		libxml2.so:textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/bin/unzip:archivers/unzip

USES=		desktop-file-utils gettext-tools gnome localbase:ldflags meson \
		pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	mjakeman

USE_GNOME=	glib20 gtk40 libadwaita
GLIB_SCHEMAS=	com.mattjakeman.ExtensionManager.gschema.xml

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
