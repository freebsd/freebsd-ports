# ex:ts=8
# Ports collection makefile for:  lunar
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	lunar
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/c-utils/  \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/c-utils/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/c-utils/

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Convert between Gregorian Solar Calendar (SC) and Lunar Calendar (LC)

ALL_TARGET=
MAN1=		lunar.1

do-install:
	@${MKDIR} ${PREFIX}/share/chinese
	${INSTALL_PROGRAM} ${WRKSRC}/lunar ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lunar.bitmap ${PREFIX}/share/chinese
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
