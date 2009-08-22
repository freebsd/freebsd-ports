# New ports collection makefile for:	mpg321
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpg321
PORTVERSION=	0.2.10
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	A free command-line mp3 player, compatible with mpg123

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad

.if defined(WITH_MPG321_SCROBBLER_PATCH)
RUN_DEPENDS=	scrobbler-helper:${PORTSDIR}/audio/p5-Audio-Scrobbler

PATCHFILES+=	mpg321-0.2.10-scrobbler-01.patch:scrobbler
PATCH_SITES+=	http://people.FreeBSD.org/~roam/ports/audio/:scrobbler \
		http://devel.ringlet.net/audio/mpg321-scrobbler/:scrobbler


MPG321_SCROBBLER_PLUGIN_NAME?=	321
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mpg123-symlink
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

MAN1=		mpg321.1

PLIST_FILES=	bin/mpg321

.if defined(WITH_MPG321_SCROBBLER_PATCH)
post-patch:
		${REINPLACE_CMD} "s/\"mpg321\"/\"${MPG321_SCROBBLER_PLUGIN_NAME}\"/" ${WRKSRC}/scrobbler.c
.endif

.include <bsd.port.mk>
