# New ports collection makefile for:	freesci
# Date created:				17 December 2000
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	freesci
PORTVERSION=	0.3.5
PORTREVISION=	8
CATEGORIES=	games emulators
MASTER_SITES=	http://www-plan.cs.colorado.edu/creichen/${PORTNAME}/ \
		http://teksolv.de/~jameson/
MASTER_SITE_SUBDIR=${PORTNAME}/stable.pkg/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable interpreter for SCI games, such as the Space Quest series

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
WANT_SDL=	yes
INSTALLS_ICONS=	yes

CFLAGS+=	${PTHREAD_CFLAGS}

MAN6=	freesci-tools.6 freesci.6

OPTIONS_DEFINE=	CONSOLE SDL GGI DIRECTFB OPTIMIZED_CFLAGS

CONSOLE_DESC=	With console support
GGI_DESC=	With GGI support
DIRECTFB_DESC=	With DirectFB support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=		-O3 -fexpensive-optimizations -fomit-frame-pointer -funroll-loops \
		-fstrict-aliasing
.if ${ARCH} != "alpha"
CFLAGS+=	-ffast-math
.endif
.endif

.if ${HAVE_SDL:Msdl}!=""
PORT_OPTIONS+=	SDL
.endif
.if exists(${LOCALBASE}/lib/libggi.so.2)
PORT_OPTIONS+=	GGI
.endif

.if ${PORT_OPTIONS:MCONSOLE}
CONFIGURE_ARGS+=	--with-console
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	yes
CONFIGURE_ARGS=		--with-sdl-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if ${PORT_OPTIONS:MDIRECTFB}
LIB_DEPENDS+=	directfb-1.4.5:${PORTSDIR}/devel/directfb
CONFIGURE_ARGS+=	--with-directfb-include=${LOCALBASE}/include/directfb \
			--with-directfb-libraries=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-directfb
.endif

.if ${PORT_OPTIONS:MGGI}
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=	--with-ggi-dir=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-ggi
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/games/freesci
	@${INSTALL_DATA} ${WRKSRC}/doc/sci.sgml ${WRKSRC}/doc/freesci.sgml \
		${WRKSRC}/doc/game-list.sgml ${WRKSRC}/doc/sci-kernel.sgml \
		${PREFIX}/share/games/freesci
.endif

.include <bsd.port.post.mk>
