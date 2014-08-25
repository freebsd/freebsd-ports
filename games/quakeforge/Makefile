# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	quakeforge
PORTVERSION=	0.5.5
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF/quake/quake/${PORTVERSION}:sf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cleaned up copy of the GPLd Quake 1 source code

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON=	generated Quake C compiler (qfcc) does not work
USE_AUTOTOOLS=	libtool
USES=		bison gmake tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
WANT_SDL=	yes

CONFIGURE_ARGS+=--with-global-cfg=${PREFIX}/etc/quakeforge.conf \
		--with-sharepath=${DATADIR} \
		--disable-optimize

OPTIONS_DEFINE=		CLIENTS OPTIMIZED_CFLAGS SDL SERVERS SKYBOXES VORBIS \
			XMMS DOCS

OPTIONS_DEFAULT=	CLIENTS OPTIMIZED_CFLAGS SERVERS DOCS

CLIENTS_DESC=		Clients
SDL_DESC=		SDL client
SERVERS_DESC=		Dedicated servers
SKYBOXES_DESC=		Install skyboxes pak
VORBIS_DESC=		Ogg Vorbis support in clients
XMMS_DESC=		XMMS support in clients

MAN1=		pak.1 qfcc.1 qflight.1 qfvis.1 wad.1
SUB_FILES=	pkg-message

DATADIR=	${Q1DIR}

NO_STAGE=	yes
.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENTS}
USE_GL=		yes
USE_XORG=	x11 xt
PLIST_SUB+=	CLIENTS=""

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
CONFIGURE_ARGS+=--with-sdl=${LOCALBASE}
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--disable-sdl
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg=${LOCALBASE} --with-vorbis=${LOCALBASE}
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=--disable-ogg --disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

.if ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS+=	libxmms.so:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--with-xmms-prefix=${LOCALBASE}
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

.else
CONFIGURE_ARGS+=--with-clients=""
PLIST_SUB+=	CLIENTS="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -funroll-loops -fomit-frame-pointer -fno-common \
		-fexpensive-optimizations -fstrict-aliasing
.   if ${ARCH} != "alpha"
CFLAGS+=	-ffast-math
.   endif
.endif

.if ${PORT_OPTIONS:MSERVERS}
PLIST_SUB+=	SERVERS=""
.else
CONFIGURE_ARGS+=--with-servers=""
PLIST_SUB+=	SERVERS="@comment "
.endif

.if ${PORT_OPTIONS:MSKYBOXES}
MASTER_SITES+=	http://www.quakeforge.net/files/:qf
DISTFILES+=	skyboxes.pak:qf
PLIST_SUB+=	SKYBOXES=""
.else
PLIST_SUB+=	SKYBOXES="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MSKYBOXES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/skyboxes.pak ${DATADIR}/QF
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.   for f in *.txt *.q1 *.q2 *.ico *.gif *.fig *.h CodingStyle
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.   endfor
.   for d in config data ideas
	${CP} -R ${WRKSRC}/doc/${d} ${DOCSDIR}
.   endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
