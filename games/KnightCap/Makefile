# New ports collection makefile for:	KnightCap
# Date created:				10 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	knightcap
PORTVERSION=	3.6
CATEGORIES=	games
MASTER_SITES=	ftp://samba.anu.edu.au/pub/KnightCap/ \
		ftp://ftp.bmtmicro.com/pub/linux/tucows/files/x11/entertain/ \
		ftp://ftp.cadvision.com/pub/linuxberg/files/x11/entertain/
DISTNAME=	KnightCap-${PORTVERSION}

MAINTAINER=	bugg@bugg.strangled.net

WRKSRC=		${WRKDIR}/Export
USE_MESA=	yes
ALL_TARGET=	KnightCap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/KnightCap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/KnightCap
.endif

.include <bsd.port.mk>
