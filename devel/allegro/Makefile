# Created by: Jimmy Olgeni <olgeni@FreeBSD.org>
# $FreeBSD$

PORTNAME=	allegro
DISTVERSION=	4.2.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-platform library for games and multimedia programming

USE_AUTOTOOLS=	autoconf
USE_GCC=	any
USE_GMAKE=	yes
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_LDCONFIG=	yes
WANT_GNOME=	yes

OPTIONS_DEFINE=	ARTS DEBUG DEVEL ESOUND JACK OPTIMIZED_CFLAGS PROFILE THREADS
OPTIONS_DEFAULT=	DEVEL OPTIMIZED_CFLAGS THREADS
DEVEL_DESC=	Install development utilities

MAKEFILE=	makefile
ALL_TARGET=	full-build
MAKE_JOBS_UNSAFE=	yes

.include "Makefile.man"

INFO=		allegro

CONFLICTS=	allegro-devel-[0-9]*
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

SHLIB_VER=	42
DEMO=		demo.c demo.dat demo.h music.txt ../readme.txt

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MARTS}
LIB_DEPENDS+=	artsc:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=--enable-artsdigi
PLIST_SUB+=	ARTS=""
.else
CONFIGURE_ARGS+=--disable-artsdigi
PLIST_SUB+=	ARTS="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-dbglib
PLIST_SUB+=	DEBUG=""
.else
CONFIGURE_ARGS+=--disable-dbglib
PLIST_SUB+=	DEBUG="@comment "
.endif

.if ${PORT_OPTIONS:MDEVEL}
INSTALL_TARGET=	full-install install-man install-info
PLIST_SUB+=	DEVEL=""
.else
INSTALL_TARGET=	mini-install install-man install-info
PLIST_SUB+=	DEVEL="@comment "
.endif

.if ${PORT_OPTIONS:MESOUNS}
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esddigi
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=--disable-esddigi
PLIST_SUB+=	ESOUND="@comment "
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=--enable-jackdigi
PLIST_SUB+=	JACK=""
.else
CONFIGURE_ARGS+=--disable-jackdigi
PLIST_SUB+=	JACK="@comment "
.endif

.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=--enable-proflib
PLIST_SUB+=	PROFILE=""
.else
CONFIGURE_ARGS+=--disable-proflib
PLIST_SUB+=	PROFILE="@comment "
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-pthreads
CPPFLAGS+=	-DHAVE_LIBPTHREAD
.else
CONFIGURE_ARGS+=--disable-pthreads
.endif

post-patch:
# Change "x.y.z" into "xy" in the shared library version.
	@${REINPLACE_CMD} -e 's|${PORTVERSION}|${SHLIB_VER}|g' \
		${WRKSRC}/makefile.ver

# Remove architecture specific optimizations.
	@${REINPLACE_CMD} -e 's|$$TARGET_ARCH||g' \
		${CONFIGURE_WRKSRC}/configure.in

# Remove "-ffast-math" flag on alpha, because it breaks.
.if ${ARCH} == "alpha"
	@${REINPLACE_CMD} -e 's|-ffast-math||g' \
		${CONFIGURE_WRKSRC}/configure.in
.endif

# Enable/disable compilation optimizations.
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		s|-ffast-math||g ; \
		s|-fomit-frame-pointer||g ; \
		s|-funroll-loops||g' \
		${CONFIGURE_WRKSRC}/configure.in
.endif

post-install:
# Documentation.
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.css  ${DOCSDIR}

# Examples.
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/demo/demo ${EXAMPLESDIR}
.   for f in ${DEMO}
	${INSTALL_DATA} ${WRKSRC}/demo/${f} ${EXAMPLESDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
