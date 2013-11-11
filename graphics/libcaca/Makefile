# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	libcaca
DISTVERSION=	0.99.beta18
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://caca.zoy.org/raw-attachment/wiki/libcaca/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Graphics library that outputs text instead of pixels

USES=		pathfix pkgconfig
USE_GNOME=	ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-doc \
		--enable-ncurses \
		--disable-java \
		--disable-csharp \
		--disable-ruby \
		--disable-python \
		--disable-cppunit \
		--disable-zzuf

DOCS=		AUTHORS COPYING COPYING.GPL COPYING.LGPL ChangeLog NEWS \
		NOTES README THANKS

OPTIONS_DEFINE=	X11 IMLIB2 FTGL SLANG DOCS
OPTIONS_DEFAULT=	X11 IMLIB2
X11_DESC=	X11 and OpenGL support
FTGL_DESC=	Freetype font rendering in OpenGL

X11_USE=	XORG=x11 GL=glut
X11_CONFIGURE_OFF=	--disable-x11 --disable-gl
IMLIB2_USE=	EFL=imlib2
IMLIB2_CONFIGURE_ENABLE=	imlib2
SLANG_LIB_DEPENDS=	libslang.so.2:${PORTSDIR}/devel/libslang2
SLANG_CONFIGURE_ENABLE=	slang

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFTGL} && ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	libftgl.so:${PORTSDIR}/graphics/ftgl
.endif

post-patch:
.if ! ${PORT_OPTIONS:MFTGL}
	@${REINPLACE_CMD} -e '/PKG_CONFIG.*ftgl/ s|ftgl|no-&|' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|-g -O2 ||g ; s| -fomit-frame-pointer||g ; \
		s|arpa\/inet.h ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g ; s| csharp||g' \
			${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcaca++.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcaca.so.0

.include <bsd.port.mk>
