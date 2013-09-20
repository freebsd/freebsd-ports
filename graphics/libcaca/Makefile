# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	libcaca
DISTVERSION=	0.99.beta18
PORTREVISION=	2
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
MAN1=		caca-config.1 cacademo.1 cacafire.1 cacaplay.1 cacaserver.1 \
		cacaview.1 img2txt.1

OPTIONS_DEFINE=	X11 IMLIB2 SLANG DOCS
OPTIONS_DEFAULT=	X11 IMLIB2
X11_DESC=	X11 and OpenGL support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
USE_GL=		glut
.else
CONFIGURE_ARGS+=--disable-x11 --disable-gl
.endif

.if ${PORT_OPTIONS:MIMLIB2}
USE_EFL+=	imlib2
.else
CONFIGURE_ARGS+=--disable-imlib2
.endif

.if ${PORT_OPTIONS:MSLANG}
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=--enable-slang
.else
CONFIGURE_ARGS+=--disable-slang
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-g -O2 ||g ; s| -fomit-frame-pointer||g ; \
		s|arpa\/inet.h ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g ; s| csharp||g' \
			${WRKSRC}/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
