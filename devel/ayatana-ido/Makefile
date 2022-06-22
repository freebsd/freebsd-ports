PORTNAME=	ayatana-ido
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Ayatana Indicator Display Objects

LICENSE=	LGPL3

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libgtest.so:devel/googletest
BUILD_DEPENDS=	vala>=0:lang/vala \
		lcov>=0:devel/lcov

USES=	cmake localbase:ldflags gnome pkgconfig

USE_GNOME=	introspection glib20 gtk30 pango atk cairo gdkpixbuf2

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AyatanaIndicators

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libayatana-ido3-0.4.so.*

.include <bsd.port.mk>
