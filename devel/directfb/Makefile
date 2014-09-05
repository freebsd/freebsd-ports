# Created by: Devaux Fabien <fab@gcu.info>
# $FreeBSD$

PORTNAME=	directfb
PORTVERSION=	1.4.13
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/downloads/Core/${DISTNAME:R}/
DISTNAME=	DirectFB-${PORTVERSION}

MAINTAINER=	anatoly.borodin@gmail.com
COMMENT=	Graphic development lightweight API

LICENSE=	LGPL21

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	FREETYPE X11 SDL UNIQUE TEST DOCS
UNIQUE_DESC=	Unique (WM Module)

OPTIONS_DEFAULT=	FREETYPE X11 SDL
OPTIONS_SUB=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool ncurses pathfix perl5 pkgconfig
USE_LDCONFIG=	yes
USE_PERL5=	build
PORTDOCS=	*

DIRECTFB_SHLIB=	5.0.8	# LT_BINARY.LT_AGE.LT_REVISION
DIRECTFB_BIN=	5	# LT_BINARY
PLIST_SUB+=	DIRECTFB_VERSION="${PORTVERSION}" \
		DIRECTFB_RELEASE="${PORTVERSION:R}" \
		DIRECTFB_SHLIB="${DIRECTFB_SHLIB}" \
		DIRECTFB_BIN="${DIRECTFB_BIN}"

CONFIGURE_ARGS=	--disable-osx --disable-extra-warnings --disable-profiling \
		--disable-debug --enable-debug-support --disable-trace \
		--enable-text --enable-gettid --enable-network \
		--disable-multi --enable-voodoo --disable-pure-voodoo \
		--enable-devmem --disable-fbdev --disable-vnc --disable-sysfs \
		--enable-jpeg --enable-zlib --enable-png --enable-gif \
		--disable-linotype --disable-video4linux \
		--disable-video4linux2 --with-gfxdrivers=all \
		--with-inputdrivers=all --with-smooth-scaling \
		--with-dither-rgb16=advanced

BROKEN_alpha=	Does not compile on alpha

DOCS_BUILD_DEPENDS=	man2html:${PORTSDIR}/textproc/man2html
FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
X11_USE=	XORG=x11,xext,xproto
X11_CONFIGURE_ENABLE=	--x11
SDL_USE=	sdl
SDL_CONFIGURE_ENABLE=	sdl
UNIQUE_CONFIGURE_ENABLE=	unique
TEST_CONFIGURE_WITH=	tests

.include <bsd.port.options.mk>

.if ${ARCH} == "arm"
PLIST_SUB+=	ARCH_ARM=""
.else
PLIST_SUB+=	ARCH_ARM="@comment "
.endif

.if ${ARCH} == "powerpc"
PLIST_SUB+=	ARCH_POWERPC=""
.else
PLIST_SUB+=	ARCH_POWERPC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/need_libc_r=yes/d ; \
		s|/usr/local|${LOCALBASE}|g ; s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${GREP} -lr alloca\.h ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|<alloca\.h>|<stdlib.h>|g'

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for f in AUTHORS ChangeLog NEWS README TODO fb.modes docs/README.screenshots docs/*.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in docs/html/*.html docs/html/*.png
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/html
.endfor

.include <bsd.port.mk>
