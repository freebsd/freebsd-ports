PORTNAME=	minder
PORTVERSION=	1.17.0
PORTREVISION=	1
CATEGORIES=	graphics
# avoid PKGBASE collision with net-p2p/minder
PKGNAMESUFFIX=	-app

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Mind-mapping application
WWW=		https://github.com/phase1geo/Minder

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	discount>0:textproc/discount
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libhandy-1.so:x11-toolkits/libhandy \
		libmarkdown.so:textproc/discount

USES=		desktop-file-utils gettext gnome libarchive localbase:ldflags \
		meson pkgconfig python:build shared-mime-info shebangfix vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	phase1geo
GH_PROJECT=	Minder
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 gtksourceview4 libxml2 pango
GLIB_SCHEMAS=	com.github.phase1geo.minder.gschema.xml
SHEBANG_FILES=	meson/post_install.py

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
