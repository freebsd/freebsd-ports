# $FreeBSD$

PORTNAME=	minder
PORTVERSION=	1.8.0
CATEGORIES=	graphics
# avoid PKGBASE collision with net-p2p/minder
PKGNAMESUFFIX=	-app

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Mind-mapping application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	discount>0:textproc/discount \
		vala:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite

USES=		desktop-file-utils gettext gnome libarchive localbase:ldflags \
		meson pkgconfig python:3.5+,build shared-mime-info shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	phase1geo
GH_PROJECT=	Minder
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 libxml2 pango
GLIB_SCHEMAS=	com.github.phase1geo.minder.gschema.xml
INSTALLS_ICONS=	yes
SHEBANG_FILES=	meson/post_install.py

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
