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
COMMENT=	Extensible drawing editor

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

RUN_DEPENDS= 	gs:${PORTSDIR}/${GSPORT} \
		latex:${PORTSDIR}/print/teTeX

USE_XLIB=	yes
USE_MOTIF= 	yes

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
