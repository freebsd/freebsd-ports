PORTNAME=	ayatana-ido
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Ayatana Indicator Display Objects
WWW=		https://github.com/AyatanaIndicators/ayatana-ido

LICENSE=	LGPL3

LIB_DEPENDS=	libgtest.so:devel/googletest \
		libharfbuzz.so:print/harfbuzz
BUILD_DEPENDS=	lcov>=0:devel/lcov

USES=		cmake gnome localbase:ldflags pkgconfig vala:build
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 introspection pango

OPTIONS_DEFINE=	DOCS
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AyatanaIndicators

PORTDOCS=	AUTHORS ChangeLog INSTALL.md NEWS README.md

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libayatana-ido3-0.4.so.*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
