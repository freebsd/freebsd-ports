# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	12.17.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sox

MAINTAINER=	dnelson@allantgroup.com
COMMENT=	SOund eXchange - universal sound sample translator

MAN1=			sox.1 play.1 soxexam.1
MLINKS=			play.1 rec.1 sox.1 soxmix.1
GNU_CONFIGURE=		yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libmp3lame.so.0)
WITH_LAME=	YES
.endif

.if exists(${LOCALBASE}/lib/libmad.so.2)
WITH_MAD=	YES
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so.2)
WITH_VORBIS=	YES
.endif

.if defined(WITH_VORBIS) || defined(WITH_LAME) || defined(WITH_MAD)
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--enable-ogg-vorbis
LIB_DEPENDS+=		vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-ogg-vorbis
.endif

.if defined(WITH_LAME)
CONFIGURE_ARGS+=	--enable-lame
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.if defined(WITH_MAD)
CONFIGURE_ARGS+=	--enable-mad
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

pre-fetch:
.if !defined(WITH_LAME)
	@${ECHO_MSG} "You can enable mp3 encoding by defining WITH_LAME."
.endif
.if !defined(WITH_MAD)
	@${ECHO_MSG} "You can enable mp3 decoding by defining WITH_MAD."
.endif
.if !defined(WITH_VORBIS)
	@${ECHO_MSG} "You can enable Ogg Vorbis support by defining WITH_VORBIS."
.endif

.include <bsd.port.post.mk>
