# New ports collection makefile for:	sox - Sound Exchange
# Version required:	12p12
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	sox-12.16
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/convert

MAINTAINER=	dnelson@emsphone.com

MAN1=		sox.1 play.1
MLINKS=		play.1 rec.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fast-ulaw --enable-fast-alaw --with-oss-dsp

.include <bsd.port.mk>
