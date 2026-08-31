PORTNAME=	minder
DISTVERSION=	2.0.9
CATEGORIES=	graphics
# avoid PKGBASE collision with net-p2p/minder
PKGNAMESUFFIX=	-app

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Mind-mapping application
WWW=		https://github.com/phase1geo/Minder

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	discount>0:textproc/discount
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite-7.so:x11-toolkits/granite7 \
		libgraphene-1.0.so:graphics/graphene \
		libjson-glib-1.0.so:devel/json-glib \
		libwebp.so:graphics/webp

USES=		desktop-file-utils gettext-tools:build gnome libarchive \
		localbase:ldflags meson pkgconfig python:build shared-mime-info \
		shebangfix vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	phase1geo
GH_PROJECT=	Minder
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 gtksourceview5 libxml2 pango
GLIB_SCHEMAS=	com.github.phase1geo.minder.gschema.xml
SHEBANG_FILES=	meson/post_install.py

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${RLN} ${STAGEDIR}${PREFIX}/bin/com.github.phase1geo.minder ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
