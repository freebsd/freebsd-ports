# New ports collection makefile for: ripenc
# Date created:         28 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	ripenc
PORTVERSION=	0.7
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.vision.net.au/ftp4/html/files/ \
		ftp://ftp.loxinfo.co.th/pub/unix/cd-writer/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jonny@jonny.eng.br

WRKSRC=		${WRKDIR}/ripenc

NO_BUILD=	Shell Script

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ripenc ${PREFIX}/bin

.include <bsd.port.mk>
