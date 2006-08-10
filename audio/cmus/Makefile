# New ports collection makefile for:	cmus
# Date created:				14 October 2005
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	cmus
PORTVERSION=	2.0.3
CATEGORIES=	audio
MASTER_SITES=	http://onion.dynserv.net/~timo/files/ \
		http://mirror.greaterscope.net/cmus/

MAINTAINER=	simon@olofsson.de
COMMENT=	Console-based music player with really cool features

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=prefix=${TARGETDIR} mandir=${TARGETDIR}/man
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	FLAC "FLAC (Free Lossless Audio Codec) support" Off \
		MAD "MPEG Audio Decoder (libmad) support" On \
		MODPLUG "libmodplug (mod, x3m, ...) support" Off \
		MUSEPACK "libmpcdec (Musepack .mpc) support" Off \
		VORBIS "Ogg/Vorbis support" On \
		LIBAO "Libao cross-platform audio library" On \
		ARTS "ARTS support" Off \
		TREMOR "Use Tremor as Ogg/Vorbis input plugin" Off

.include <bsd.port.pre.mk>

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=CONFIG_FLAC=y
PLIST_SUB+=	FLAC=""
.else
CONFIGURE_ARGS+=CONFIG_FLAC=n
PLIST_SUB+=	FLAC="@comment "
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=CONFIG_MAD=y
PLIST_SUB+=	MAD=""
.else
CONFIGURE_ARGS+=CONFIG_MAD=n
PLIST_SUB+=	MAD="@comment "
.endif

.if defined(WITH_MODPLUG)
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
CONFIGURE_ARGS+=CONFIG_MODPLUG=y
PLIST_SUB+=	MODPLUG=""
.else
CONFIGURE_ARGS+=CONFIG_MODPLUG=n
PLIST_SUB+=	MODPLUG="@comment "
.endif

.if defined(WITH_MUSEPACK)
LIB_DEPENDS+=	mpcdec:${PORTSDIR}/audio/libmpcdec
CONFIGURE_ARGS+=CONFIG_MPC=y
PLIST_SUB+=	MPC=""
.else
CONFIGURE_ARGS+=CONFIG_MPC=n
PLIST_SUB+=	MPC="@comment "
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=CONFIG_VORBIS=y
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=CONFIG_VORBIS=n
PLIST_SUB+=	VORBIS="@comment "
.endif

.if !defined(WITHOUT_LIBAO)
LIB_DEPENDS+=	ao:${PORTSDIR}/audio/libao
CONFIGURE_ARGS+=CONFIG_AO=y
PLIST_SUB+=	AO=""
.else
CONFIGURE_ARGS+=CONFIG_AO=n
PLIST_SUB+=	AO="@comment "
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=CONFIG_ARTS=y
PLIST_SUB+=	ARTS=""
.else
CONFIGURE_ARGS+=CONFIG_ARTS=n
PLIST_SUB+=	ARTS="@comment "
.endif

.if defined(WITH_TREMOR)
LIB_DEPENDS+=	vorbisidec:${PORTSDIR}/audio/libtremor
CONFIGURE_ARGS+=CONFIG_TREMOR=y
.endif

MAN1=	cmus.1 cmus-remote.1

post-extract:
	@${REINPLACE_CMD} -e 's,-lncursesw,-lncurses,g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL} ${WRKSRC}/cmus-status-display ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
