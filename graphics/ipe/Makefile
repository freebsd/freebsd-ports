# New ports collection makefile for:	Ipe
# Date created:				October 25 2000
# Whom:					bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	Ipe
PORTVERSION=	5.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-magdeburg.de/pub/ipe/ \
		ftp://ftp.cs.ruu.nl/pub/mirror/ipe/ \
		ftp://ftp.cs.ust.hk/pub/ipe/

MAINTAINER=	bremner@unb.ca

RUN_DEPENDS= 	gs:${PORTSDIR}/print/ghostscript6 \
		latex:${PORTSDIR}/print/teTeX

USE_XLIB=	yes
REQUIRES_MOTIF= yes

.include <bsd.port.mk>
