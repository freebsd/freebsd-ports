# New ports collection makefile for:	sox - Sound Exchange
# Version required:	12p12
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.9 1997/02/04 10:32:34 max Exp $
#

DISTNAME=	sox-12.16
CATEGORIES=	audio
MASTER_SITES=	http://home.sprynet.com/~cbagwell/

MAINTAINER=	dnelson@emsphone.com

MAN1=		sox.1 play.1
MLINKS=		play.1 rec.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fast-ulaw --enable-fast-alaw

.include <bsd.port.mk>
