PORTNAME=	libcaca
DISTVERSION=	0.99.beta20
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/cacalabs/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Graphics library that outputs text instead of pixels
WWW=		http://caca.zoy.org/wiki/libcaca \
		https://github.com/cacalabs/libcaca

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool localbase ncurses pathfix pkgconfig tar:bz2
CPE_VENDOR=	libcaca_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc \
		--enable-ncurses \
		--disable-java \
		--disable-csharp \
		--disable-ruby \
		--disable-python \
		--disable-cppunit \
		--disable-zzuf
MAKE_ENV=	V=1
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	SOVERSION=${DISTVERSION:S|beta||}

PORTDOCS=	AUTHORS NEWS NOTES README THANKS

OPTIONS_DEFINE=		DOCS FTGL IMLIB2 SLANG X11
OPTIONS_DEFAULT=	IMLIB2 X11

FTGL_DESC=		Freetype font rendering in OpenGL
X11_DESC=		X11 and OpenGL support

FTGL_IMPLIES=		X11
FTGL_LIB_DEPENDS=	libftgl.so:graphics/ftgl

IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_CONFIGURE_ENABLE=imlib2

SLANG_LIB_DEPENDS=	libslang.so.2:devel/libslang2
SLANG_CONFIGURE_ENABLE=	slang=${LOCALBASE}

X11_USES=		gl xorg
X11_USE=		GL=gl,glu,glut XORG=x11
X11_CONFIGURE_ENABLE=	gl x11

post-patch:
	@${REINPLACE_CMD} -e 's|-g -O2 ||g ; s| -fomit-frame-pointer||g ; \
		s| -fno-strength-reduce||g ; s|arpa\/inet.h ||g' \
		${WRKSRC}/configure

post-patch-FTGL-off:
	@${REINPLACE_CMD} -e '/PKG_CONFIG.*ftgl/ s|ftgl|no-&|' \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
