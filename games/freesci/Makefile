# New ports collection makefile for:	freesci
# Date created:				17 December 2000
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	freesci
PORTVERSION=	0.3.5
CATEGORIES=	games emulators
MASTER_SITES=	http://www-plan.cs.colorado.edu/creichen/${PORTNAME}/ \
		http://teksolv.de/~jameson/
MASTER_SITE_SUBDIR=${PORTNAME}/stable.pkg/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable interpreter for SCI games, such as the Space Quest series

USE_BZIP2=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
WANT_SDL=	yes

CONFIGURE_TARGET=
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

MAN6=	freesci-tools.6 freesci.6

OPTIONS=	CONSOLE		 "With console support"			off \
		SDL		 "With SDL support"			off \
		GGI		 "With GGI support"			off \
		DIRECTFB	 "With DirectFB support"		off \
		OPTIMIZED_CFLAGS "Build with code optimizations"	off

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
