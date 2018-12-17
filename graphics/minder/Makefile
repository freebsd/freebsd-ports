# $FreeBSD$

PORTNAME=	minder
PORTVERSION=	1.1.3
CATEGORIES=	graphics
PKGNAMESUFFIX=	-app # avoid PKGBASE collision with net-p2p/minder

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Mind-mapping application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libgranite.so:x11-toolkits/granite

USES=		gettext gnome meson pkgconfig python:3.5+,build
USE_GITHUB=	yes
GH_ACCOUNT=	phase1geo
GH_PROJECT=	Minder
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libxml2 pango
GLIB_SCHEMAS=	com.github.phase1geo.minder.gschema.xml
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD} # for meson/post_install.py

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
