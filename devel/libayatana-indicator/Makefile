PORTNAME=	libayatana-indicator
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Ayatana Indicators Shared Library
WWW=		https://github.com/AyatanaIndicators/libayatana-indicator

LICENSE=	GPLv3

LIB_DEPENDS=	libayatana-ido3-0.4.so:devel/ayatana-ido \
		libgtest.so:devel/googletest \
		libharfbuzz.so:print/harfbuzz
BUILD_DEPENDS=	lcov>=0:devel/lcov

USES=		cmake gnome localbase:ldflags pkgconfig vala:build

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 introspection pango

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AyatanaIndicators

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README.md
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libayatana-indicator3.so*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/libayatana-indicator/ayatana-indicator-loader3

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
