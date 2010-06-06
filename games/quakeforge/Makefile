# New ports collection makefile for:	QuakeForge
# Date created:		4 January 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	quakeforge
PORTVERSION=	0.5.5
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/quake/quake/${PORTVERSION}:sf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Cleaned up copy of the GPLd Quake 1 source code

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON=	generated Quake C compiler (qfcc) does not work
USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
WANT_SDL=	yes

CONFIGURE_ARGS+=--with-global-cfg=${PREFIX}/etc/quakeforge.conf \
		--with-sharepath=${DATADIR} \
		--disable-optimize

OPTIONS=	CLIENTS "Build clients" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" off \
		SERVERS "Build dedicated servers" on \
		SKYBOXES "Install skyboxes pak" off \
		VORBIS "Enable Ogg Vorbis support in clients" off \
		XMMS "Enable XMMS support in clients" off

MAN1=		pak.1 qfcc.1 qflight.1 qfvis.1 wad.1
SUB_FILES=	pkg-message

DATADIR=	${Q1DIR}

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CLIENTS)
USE_GL=		yes
USE_XORG=	x11 xt
PLIST_SUB+=	CLIENTS=""

.if defined(WITH_SDL)
USE_SDL=	sdl
CONFIGURE_ARGS+=--with-sdl=${LOCALBASE}
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--disable-sdl
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg=${LOCALBASE} --with-vorbis=${LOCALBASE}
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=--disable-ogg --disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--with-xmms-prefix=${LOCALBASE}
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

.else
CONFIGURE_ARGS+=--with-clients=""
PLIST_SUB+=	CLIENTS="@comment "
.endif	# WITH_CLIENTS

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-loops -fomit-frame-pointer -fno-common \
		-fexpensive-optimizations -fstrict-aliasing
.   if ${ARCH} != "alpha"
CFLAGS+=	-ffast-math
.   endif
.endif

.if !defined(WITHOUT_SERVERS)
PLIST_SUB+=	SERVERS=""
.else
CONFIGURE_ARGS+=--with-servers=""
PLIST_SUB+=	SERVERS="@comment "
.endif

.if defined(WITH_SKYBOXES)
MASTER_SITES+=	http://www.quakeforge.net/files/:qf
DISTFILES+=	skyboxes.pak:qf
PLIST_SUB+=	SKYBOXES=""
.else
PLIST_SUB+=	SKYBOXES="@comment "
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
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
