# New ports collection makefile for:	amrcoder
# Date created:				5 March 2005
# Whom:					Andrew Wingorodov (Wingborn) <programmer@coolsoft.ru>
#
# $FreeBSD$
#
#

PORTNAME=	amrcoder
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://coolsoft.ru/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	programmer@coolsoft.ru
COMMENT=	AMR encoder/decoder for Mbuni MMS Gateway (www.mbuni.org)

MAN1=		amrdecoder.1 amrencoder.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		"Does not build on ia64 or sparc64"
.endif

.include <bsd.port.post.mk>
