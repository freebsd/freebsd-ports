# New ports collection makefile for:	QuakeForge
# Date created:		4 January 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	quakeforge
PORTVERSION=	0.5.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	quake/:sf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Cleaned up copy of the GPLd Quake 1 source code

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_BISON=	yes
WANT_SDL=	yes

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--with-global-cfg=${PREFIX}/etc/quakeforge.conf \
		--with-sharepath=${DATADIR} \
		--disable-optimize

OPTIONS=	CLIENTS "Build clients" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" off \
		SERVERS "Build dedicated servers" on \
		SKYBOXES "Install skyboxes pak" off \
		STATIC_PLUGINS "Build plugins into executable" off \
		VORBIS "Enable Ogg Vorbis support in clients" off \
		XMMS "Enable XMMS support in clients" off

MAN1=		pak.1 qfcc.1 qflight.1 qfvis.1 wad.1

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/quakeforge

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.if defined(WITH_CLIENTS)
USE_XLIB=	yes
PLIST_SUB+=	CLIENTS=""

.if defined(WITH_SDL) || ${HAVE_SDL:Msdl}!=""
USE_SDL=	sdl
CONFIGURE_ARGS+=--with-sdl=${LOCALBASE}
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--without-sdl
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_VORBIS) || exists(${LOCALBASE}/lib/libvorbis.so.3)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg=${LOCALBASE} --with-vorbis=${LOCALBASE}
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=--without-ogg --without-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

.if defined(WITH_XMMS) || exists(${X11BASE}/lib/libxmms.so.4)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--with-xmms-prefix=${X11BASE}
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--without-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

.else
CONFIGURE_ARGS+=--without-clients
PLIST_SUB+=	CLIENTS="@comment "
.endif # WITH_CLIENTS

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-loops -fomit-frame-pointer -fno-common \
		-fexpensive-optimizations -fstrict-aliasing
.   if ${ARCH} != "alpha"
CFLAGS+=	-ffast-math
.   endif
.endif

.if defined(WITH_SERVERS)
PLIST_SUB+=	SERVERS=""
.else
CONFIGURE_ARGS+=--without-servers
PLIST_SUB+=	SERVERS="@comment "
.endif

.if defined(WITH_SKYBOXES)
MASTER_SITES+=	http://www.quakeforge.net/files/:qf
DISTFILES+=	skyboxes.pak:qf
PLIST_SUB+=	SKYBOXES=""
.else
PLIST_SUB+=	SKYBOXES="@comment "
.endif

.if defined(WITH_STATIC_PLUGINS)
PLIST_SUB+=	PLUGINS="@comment "
CONFIGURE_ARGS+=--with-static-plugins
.else
PLIST_SUB+=	PLUGINS=""
.endif

post-install:
.if defined(WITH_SKYBOXES)
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/skyboxes.pak ${DATADIR}/QF
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.   for f in *.txt *.q1 *.q2 *.ico *.gif *.fig *.h CodingStyle
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.   endfor
.   for d in config data ideas
	${CP} -R ${WRKSRC}/doc/${d} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
