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

post-extract:
	@${RM} ${WRKSRC}/*.o

.include <bsd.port.mk>
