# New ports collection makefile for:	freesci
# Date created:				17 December 2000
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	freesci
PORTVERSION=	0.3.4c
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://teksolv.de/~jameson/
MASTER_SITE_SUBDIR=${PORTNAME}/stable.pkg/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable interpreter for SCI games, such as the Space Quest series

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
WANT_SDL=	yes

CONFIGURE_TARGET=
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

MAN6=	freesci-tools.6 freesci.6

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS=		-O3 -fexpensive-optimizations -fomit-frame-pointer -funroll-loops \
		-fstrict-aliasing
.if ${ARCH} != "alpha"
CFLAGS+=	-ffast-math
.endif
.endif

.if ${HAVE_SDL:Msdl}!=""
WITH_SDL=	yes
.endif
.if exists(${LOCALBASE}/lib/libdirectfb-0.9.so.16)
WITH_DIRECTFB=	yes
.endif
.if exists(${LOCALBASE}/lib/libggi.so.2)
WITH_GGI=	yes
.endif

.if defined(WITH_CONSOLE)
CONFIGURE_ARGS+=	--with-console
.endif

.if defined(WITH_SDL) && !defined(WITHOUT_SDL)
USE_SDL=	yes
CONFIGURE_ARGS=		--with-sdl-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if defined(WITH_DIRECTFB) && !defined(WITHOUT_DIRECTFB)
LIB_DEPENDS+=	directfb-0.9.16:${PORTSDIR}/devel/directfb
CONFIGURE_ARGS+=	--with-directfb-include=${LOCALBASE}/include/directfb \
			--with-directfb-libraries=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-directfb
.endif

.if defined(WITH_GGI) && !defined(WITHOUT_GGI)
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=	--with-ggi-dir=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-ggi
.endif

pre-everything::
.if !defined(WITH_CONSOLE)
	@${ECHO_MSG} "Define WITH_CONSOLE to build console support"
.endif
.if !defined(WITH_SDL)
	@${ECHO_MSG} "Define WITH_SDL to build with SDL support"
.endif
.if !defined(WITH_GGI)
	@${ECHO_MSG} "Define WITH_GGI to build with GGI support"
.endif
.if !defined(WITH_DIRECTFB)
	@${ECHO_MSG} "Define WITH_DIRECTFB to build with DirectFB support"
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to build with extra optimizations"
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/games/freesci
	@${INSTALL_DATA} ${WRKSRC}/doc/sci.sgml ${WRKSRC}/doc/freesci.sgml \
		${WRKSRC}/doc/game-list.sgml ${WRKSRC}/doc/sci-kernel.sgml \
		${PREFIX}/share/games/freesci
.endif

.include <bsd.port.post.mk>
