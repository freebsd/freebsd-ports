# New ports collection makefile for:	allegro
# Date created:		23-Feb-2001
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
DISTVERSION=	4.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	alleg

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A cross-platform library for games and multimedia programming

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_XLIB=	yes
WANT_GNOME=	yes

USE_AUTOTOOLS=	autoconf:259

.include "Makefile.man"

INFO=		allegro

OPTIONS=	ARTS "Enable Arts support" off \
		DEBUG_LIB "Build debugging library" off \
		DEV_UTILS "Build development utilities" on \
		ESOUND "Enable Esound support" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		PROFILE_LIB "Build profiling library" off \
		THREADS "Enable threads" on

MAKEFILE=	makefile
ALL_TARGET=	full-build

INSTALLS_SHLIB=	yes
SHLIB_VER=	42
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"
DEMO=		demo.c demo.dat demo.h music.txt ../readme.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-include-allegro-inline-fmaths.in
.endif

.if defined(WITH_ARTS) || exists(${LOCALBASE}/lib/libartsc.so.0)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--enable-artsdigi
PLIST_SUB+=	ARTS=""
.else
CONFIGURE_ARGS+=	--disable-artsdigi
PLIST_SUB+=	ARTS="@comment "
.endif

.if defined(WITH_DEBUG_LIB)
CONFIGURE_ARGS+=	--enable-dbglib
PLIST_SUB+=	DEBUG_LIB=""
.else
CONFIGURE_ARGS+=	--disable-dbglib
PLIST_SUB+=	DEBUG_LIB="@comment "
.endif

.if !defined(WITHOUT_DEV_UTILS)
INSTALL_TARGET=	full-install install-man install-info
PLIST_SUB+=	DEV_UTILS=""
.else
INSTALL_TARGET=	mini-install install-man install-info
PLIST_SUB+=	DEV_UTILS="@comment "
.endif

.if defined(WITH_ESOUND) || ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-esddigi
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=	--disable-esddigi
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITH_PROFILE_LIB)
CONFIGURE_ARGS+=	--enable-proflib
PLIST_SUB+=	PROFILE_LIB=""
.else
CONFIGURE_ARGS+=	--disable-proflib
PLIST_SUB+=	PROFILE_LIB="@comment "
.endif

.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-pthreads
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -DHAVE_LIBPTHREAD" \
		LDFLAGS="${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=	--disable-pthreads
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
