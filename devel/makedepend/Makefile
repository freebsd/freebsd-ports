# New ports collection makefile for:	makedepend
# Date created:				August 15th 1997
# Whom:					Ian Vaudrey <i.vaudrey@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	makedepend
PORTVERSION=	2000.09.07
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/
DISTNAME=	cyrus-imapd-2.0.7

MAINTAINER=	roam@orbitel.bg

WRKSRC=		${WRKDIR}/${DISTNAME}/makedepend
GNU_CONFIGURE=	YES

MAN1=		makedepend.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makedepend ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mkdepend.man ${PREFIX}/man/man1/makedepend.1

.include <bsd.port.mk>
# DO NOT DELETE
