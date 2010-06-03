# New ports collection makefile for:	DirectFB
# Date created:				19 October 2002
# Whom:					Devaux Fabien <fab@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	directfb
PORTVERSION=	1.4.3
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/downloads/Core/${DISTNAME:R}/
DISTNAME=	DirectFB-${PORTVERSION}

MAINTAINER=	anatoly.borodin@gmail.com
COMMENT=	Graphic development lightweight API

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

OPTIONS=	FREETYPE2	"Enable Freetype support" on \
		X11		"Enable X11 backend" on \
		SDL		"Enable SDL backend" on \
		UNIQUE		"Enable Unique (WM Module)" off \
		TESTS		"Install test apps" off

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes

DIRECTFB_SHLIB=	3 # LT_CURRENT
DIRECTFB_BIN=	0 # LT_BINARY
PLIST_SUB+=	DIRECTFB_VERSION="${PORTVERSION}" \
		DIRECTFB_RELEASE="${PORTVERSION:R}" \
		DIRECTFB_SHLIB="${DIRECTFB_SHLIB}" \
		DIRECTFB_BIN="${DIRECTFB_BIN}"

CONFIGURE_ARGS=	--disable-osx --disable-extra-warnings --disable-profiling \
		--disable-debug --enable-debug-support --disable-trace \
		--enable-text --enable-gettid --enable-network \
		--disable-multi --enable-voodoo --enable-devmem \
		--disable-fbdev --disable-vnc --disable-sysfs --enable-jpeg \
		--enable-zlib --enable-png --enable-gif --disable-video4linux \
		--disable-video4linux2 --with-gfxdrivers=all \
		--with-inputdrivers=all --with-smooth-scaling \
		--with-dither-rgb16=advanced

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	man2html:${PORTSDIR}/textproc/man2html
PORTDOCS=	*
DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README TODO \
		docs/README* docs/*.html docs/html/*.html docs/html/*.png
.endif

.if defined(WITH_FREETYPE2)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--enable-freetype
PLIST_SUB+=	FREETYPE2=""
.else
CONFIGURE_ARGS+=	--disable-freetype
PLIST_SUB+=	FREETYPE2="@comment "
.endif

.if defined(WITH_X11)
USE_XORG+=	x11 xproto
CONFIGURE_ARGS+=	--enable-x11
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=	--disable-x11
PLIST_SUB+=	X11="@comment "
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
CONFIGURE_ARGS+=	--enable-sdl
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=	--disable-sdl
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_UNIQUE)
CONFIGURE_ARGS+=	--enable-unique
PLIST_SUB+=	UNIQUE=""
.else
CONFIGURE_ARGS+=	--disable-unique
PLIST_SUB+=	UNIQUE="@comment "
.endif

.if defined(WITH_TESTS)
CONFIGURE_ARGS+=	--with-tests
PLIST_SUB+=	TESTS=""
.else
CONFIGURE_ARGS+=	--without-tests
PLIST_SUB+=	TESTS="@comment "
.endif

MAN1=		directfb-csource.1 dfbg.1
MAN5=		directfbrc.5

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lc_r|${PTHREAD_LIBS}|g ; s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|%%LTMAIN%%|${LTMAIN}|g ; s|/usr/local|${LOCALBASE}|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${GREP} -lr alloca\.h ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|<alloca\.h>|<stdlib.h>|g'

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC} && \
	for f in ${DOCS}; do \
		if [ $${f##*/html/*} ]; then \
			${INSTALL_DATA} $$f ${DOCSDIR}; \
		else \
			${INSTALL_DATA} $$f ${DOCSDIR}/html; \
		fi; \
	done
.endif

.include <bsd.port.post.mk>
