# New ports collection makefile for:	cd-discid
# Date created:			July 29, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	cd-discid
PORTVERSION=	0.7
CATEGORIES=	audio
MASTER_SITES=	http://frantica.lly.org/~rcw/cd-discid/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	mchopra@engmail.uwaterloo.ca

WRKSRC=		${WRKDIR}/${PKGNAME}

MAN1=	cd-discid.1

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o cd-discid cd-discid.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cd-discid ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cd-discid.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
