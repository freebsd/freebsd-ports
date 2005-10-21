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
MASTER_SITES=	# disappeared
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AMR encoder/decoder for Mbuni MMS Gateway (www.mbuni.org)

DEPRECATED=	mastersite disappeared
EXPIRATION_DATE=	2005-12-31

MAN1=		amrdecoder.1 amrencoder.1

post-extract:
	@${RM} ${WRKSRC}/*.o

.include <bsd.port.mk>
