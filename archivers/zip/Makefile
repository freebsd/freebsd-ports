# New ports collection makefile for:	zip (without encryption)
# Date created:		22 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	2.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/infozip/src/
DISTNAME=	zip23

MAINTAINER=	ache@FreeBSD.org

Y2K=		http://www.cdrom.com/pub/infozip/FAQ.html#Y2K

WRKSRC=		${WRKDIR}/zip-2.3
MAKEFILE=	unix/Makefile
ALL_TARGET=	generic
MAN1=		zip.1

do-install:
.for file in zip zipcloak zipnote zipsplit
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/zip.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
