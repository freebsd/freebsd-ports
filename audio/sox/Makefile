# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	12.17.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sox

MAINTAINER=		dnelson@emsphone.com

MAN1=			sox.1 play.1 soxexam.1
MLINKS=			play.1 rec.1 sox.1 soxmix.1
GNU_CONFIGURE=		yes

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--with-ogg-vorbisinc=${LOCALBASE}/include \
		 	--with-ogg-vorbislib=${LOCALBASE}/lib
LIB_DEPENDS+=		vorbis.1:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--with-ogg-vorbisinc=no
.endif

.include <bsd.port.mk>
