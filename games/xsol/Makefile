# New ports collection makefile for:    xsol
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xsol
PORTVERSION=	2.1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.simcb.ru/pub/unix/src/
DISTNAME=	${PORTNAME}-new

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
MAN6=		xsol.6

post-patch:
	@${ECHO} "MANSUFFIX=6" >> ${WRKSRC}/Imakefile

.include <bsd.port.mk>
