PORTNAME=	libayatana-appindicator
PORTVERSION=	0.5.94
CATEGORIES=	devel

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Ayatana Application Indicators Shared Library
WWW=		https://github.com/AyatanaIndicators/libayatana-appindicator

LICENSE=	LGPL3

LIB_DEPENDS=	libayatana-ido3-0.4.so:devel/ayatana-ido \
		libayatana-indicator3.so:devel/libayatana-indicator \
		libdbusmenu-glib.so:devel/libdbusmenu \
		libharfbuzz.so:print/harfbuzz

USES=		cmake gnome localbase:ldflags pkgconfig pathfix

USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 introspection pango
CMAKE_OFF=	ENABLE_BINDINGS_MONO \
		ENABLE_BINDINGS_VALA \
		FLAVOUR_GTK2 \
		ENABLE_GTKDOC

USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,--undefined-version

USE_GITHUB=	yes
GH_ACCOUNT=	AyatanaIndicators

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libayatana-appindicator3.so.*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
