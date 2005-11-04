# New ports collection makefile for:	cmus
# Date created:				14 October 2005
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	cmus
PORTVERSION=	1.6.3
CATEGORIES=	audio
MASTER_SITES=	http://onion.dynserv.net/~timo/files/

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
.if exists(${LOCALBASE}/lib/libartsc.so)
WITH_ARTS=	yes
.endif

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

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS=""
.else
PLIST_SUB+=	ARTS="@comment "
PREMSG+=	Define WITH_ARTS=yes to enable arts output support.\n
.endif

pre-everything::
	@${ECHO_CMD}
	@${PRINTF} "${PREMSG}"
	@${ECHO_CMD}

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		"s|/bin/bash|${LOCALBASE}/bin/bash|; \
		 /^#include/s|\<id3.h\>|\"id3.h\"|; \
		 s|-lncursesw|-lncurses|g"

.include <bsd.port.post.mk>
