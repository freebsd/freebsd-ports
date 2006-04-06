# New ports collection makefile for:	cmus
# Date created:				14 October 2005
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	cmus
PORTVERSION=	2.0.0
CATEGORIES=	audio
MASTER_SITES=	http://onion.dynserv.net/~timo/files/ \
		http://mirror.greaterscope.net/cmus/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Console-based music player with really cool features

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac \
		mad:${PORTSDIR}/audio/libmad

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libvorbisfile.so)
WITH_VORBIS=	yes
.endif
.if exists(${LOCALBASE}/lib/libmodplug.so)
WITH_MODPLUG=	yes
.endif
.if exists(${LOCALBASE}/lib/libvorbisidec.so)
WITH_TREMOR=	yes
.endif
.if exists(${LOCALBASE}/lib/libmpcdec.so)
WITH_MUSEPACK=	yes
.endif
.if exists(${LOCALBASE}/lib/libao.so)
WITH_LIBAO=	yes
.endif
.if exists(${LOCALBASE}/lib/libartsc.so)
WITH_ARTS=	yes
.endif

PREMSG=		\n

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
PREMSG+=	Define WITH_VORBIS=yes to enable OGG/Vorbis support.\n
.endif

.if defined(WITH_MODPLUG)
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
PLIST_SUB+=	MODPLUG=""
.else
PLIST_SUB+=	MODPLUG="@comment "
PREMSG+=	Define WITH_MODPLUG=yes to enable module music files.\n
.endif

.if defined(WITH_TREMOR)
LIB_DEPENDS+=	vorbisidec:${PORTSDIR}/audio/libtremor
CONFIGURE_ARGS+=--with-tremor
.else
PREMSG+=	Define WITH_TREMOR=yes to enable libtremor support.\n
.endif

.if defined(WITH_MUSEPACK)
LIB_DEPENDS+=	mpcdec:${PORTSDIR}/audio/libmpcdec
PLIST_SUB+=	MPC=""
.else
PLIST_SUB+=	MPC="@comment "
PREMSG+=	Define WITH_MUSEPACK=yes to enable musepack support.\n
.endif

.if defined(WITH_LIBAO)
LIB_DEPENDS+=	ao:${PORTSDIR}/audio/libao
PLIST_SUB+=	AO=""
.else
PLIST_SUB+=	AO="@comment "
PREMSG+=	Define WITH_LIBAO=yes to enable the libao output library.\n
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS=""
.else
PLIST_SUB+=	ARTS="@comment "
PREMSG+=	Define WITH_ARTS=yes to enable arts output support.\n
.endif

pre-everything::
	@${PRINTF} "${PREMSG}"
	@${ECHO_CMD}

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		"s|/bin/bash|${LOCALBASE}/bin/bash|; \
		 s|-lncursesw|-lncurses|g"

.include <bsd.port.post.mk>
