# New ports collection makefile for:	allegro
# Date created:		23-Feb-2001
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
DISTVERSION=	4.3.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/${PORTNAME}-unstable/${PORTVERSION}
PKGNAMESUFFIX=	-devel

MAINTAINER=	EitanAdlerList@gmail.com
COMMENT=	A cross-platform library for games and multimedia programming

USE_AUTOTOOLS=	autoconf:262
USE_GMAKE=	yes
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_LDCONFIG=	yes
WANT_GNOME=	yes

OPTIONS=	AL "Enable OpenAL support" off \
		ARTS "Enable Arts support" off \
		DEBUG "Build debugging library" off \
		DEVEL "Build development utilities" on \
		ESOUND "Enable Esound support" off \
		JACK "Enable JACK support" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		PROFILE "Build profiling library" off \
		THREADS "Enable threads" on

MAKEFILE=	makefile
ALL_TARGET=	full-build

.include "Makefile.man"

INFO=		allegro

CONFLICTS=	allegro-[0-9]*
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

DEMO=		demo.c demo.dat demo.h music.txt ../readme.txt
SHLIB_VER=	43

PORTSCOUT=	limit:^4\.3\.[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_AL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
CONFIGURE_ARGS+=--enable-sgialdigi
PLIST_SUB+=	AL=""
.else
CONFIGURE_ARGS+=--disable-sgialdigi
PLIST_SUB+=	AL="@comment "
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=--enable-artsdigi
PLIST_SUB+=	ARTS=""
.else
CONFIGURE_ARGS+=--disable-artsdigi
PLIST_SUB+=	ARTS="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-dbglib
PLIST_SUB+=	DEBUG=""
.else
CONFIGURE_ARGS+=--disable-dbglib
PLIST_SUB+=	DEBUG="@comment "
.endif

.if !defined(WITHOUT_DEVEL)
INSTALL_TARGET=	full-install install-man install-info
PLIST_SUB+=	DEVEL=""
.else
INSTALL_TARGET=	mini-install install-man install-info
PLIST_SUB+=	DEVEL="@comment "
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esddigi
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=--disable-esddigi
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=--enable-jackdigi
PLIST_SUB+=	JACK=""
.else
CONFIGURE_ARGS+=--disable-jackdigi
PLIST_SUB+=	JACK="@comment "
.endif

.if defined(WITH_PROFILE)
CONFIGURE_ARGS+=--enable-proflib
PLIST_SUB+=	PROFILE=""
.else
CONFIGURE_ARGS+=--disable-proflib
PLIST_SUB+=	PROFILE="@comment "
.endif

.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=--enable-pthreads
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -DHAVE_LIBPTHREAD" \
		LDFLAGS="${PTHREAD_LIBS}"
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

# Threading libraries.
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/' ${WRKSRC}/aclocal.m4

# Enable/disable compilation optimizations.
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		s|-ffast-math||g ; \
		s|-fomit-frame-pointer||g ; \
		s|-funroll-loops||g' \
		${CONFIGURE_WRKSRC}/configure.in
.endif

post-install:
# Documentation.
.if !defined(NOPORTDOCS)
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
