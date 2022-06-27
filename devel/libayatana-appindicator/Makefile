PORTNAME=	libayatana-appindicator
PORTVERSION=	0.5.91
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Ayatana Application Indicators Shared Library

LICENSE=	LGPL3

BUILD_DEPENDS=	lcov>=0:devel/lcov

USES=	cmake localbase:ldflags gnome pkgconfig

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libgtest.so:devel/googletest \
		libayatana-indicator3.so:devel/libayatana-indicator \
		libdbusmenu-glib.so:devel/libdbusmenu \
		libayatana-ido3-0.4.so:devel/ayatana-ido

USE_GNOME=	introspection gtk30 glib20 pango atk cairo gdkpixbuf2
CMAKE_OFF=	ENABLE_BINDINGS_MONO \
		FLAVOUR_GTK2 \
		ENABLE_BINDINGS_VALA

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AyatanaIndicators

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libayatana-appindicator3.so.*

.include <bsd.port.mk>
