# New ports collection makefile for:	sox - Sound Exchange
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sox
PORTVERSION=	12.16
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/convert

MAINTAINER=	dnelson@emsphone.com

MAN1=		sox.1 play.1
MLINKS=		play.1 rec.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fast-ulaw --enable-fast-alaw --with-oss-dsp

.if defined(USE_GSM)
CONFIGURE_ARGS+= --with-gsmlib=${PREFIX}/lib --with-gsminc=${PREFIX}/include
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
.endif

.include <bsd.port.mk>
