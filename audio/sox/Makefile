# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	12.17.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sox

MAINTAINER=		dnelson@emsphone.com

MAN1=			sox.1 play.1 soxexam.1
MLINKS=			play.1 rec.1
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-fast-ulaw --enable-fast-alaw

.if defined(WITH_GSM)
CONFIGURE_ARGS+=	--with-gsmlib=${LOCALBASE}/lib \
		 	--with-gsminc=${LOCALBASE}/include
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm
.else
CONFIGURE_ARGS+=	--with-gsminc=no
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--with-ogg-vorbisinc=${LOCALBASE}/include \
		 	--with-ogg-vorbislib=${LOCALBASE}/lib
LIB_DEPENDS+=		vorbis.0:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--with-ogg-vorbisinc=no
.endif

.include <bsd.port.mk>
